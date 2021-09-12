// Server API makes it possible to hook into various parts of Gridsome
// on server-side and add custom data to the GraphQL data layer.
// Learn more: https://gridsome.org/docs/server-api/

// Changes here require a server restart.
// To restart press CTRL + C in terminal and run `gridsome develop`

const fs = require('fs').promises;
const path = require('path');
const crypto = require('crypto');
const shellExec = require('shell-exec');

const problemRegex = /^\/\/ Problem https:\/\/open\.kattis\.com\/problems\/(\w+?)\s*\n/;

async function parseSrcFile(filePath) {
    const fileBuffer = await fs.readFile(filePath);
    
    // Read problem id from file comment
    const fileText = fileBuffer.toString();
    const matches = fileText.match(problemRegex);
    if(matches === null) {
        console.warn(`Source file ${filePath} doesn't match problem regex!`);
        return null;
    }
    const problemID = matches[1];
    
    const hashSum = crypto.createHash('sha256');
    hashSum.update(fileBuffer);
    const hex = hashSum.digest('hex');
    
    return {
        hash: hex,
        problemID,
        fileText
    };
}

const srcDir = path.join(__dirname, '..', 'solutions');
const previousBuildDir = path.join(__dirname, '..', '..', 'previous');

module.exports = function(api) {
    
    api.afterBuild(async ({config}) => {
        const solutionsCollection = api._store.getCollection('Solutions').collection;
        const solutionsData = [...solutionsCollection.data];
    
        // Write file to static serve containing source meta
        await fs.writeFile(path.join(config.outputDir, 'solutions.json'), JSON.stringify(solutionsData.map(solution => ({
            hash: solution.hash,
            problemID: solution.problemID,
            fileName: solution.fileName
        })), null, 4), 'utf-8');
        
        const srcFilePath = path.join(config.outputDir, 'src');
        const compiledPath = path.join(config.outputDir, 'compiled');
        await Promise.allSettled([
            fs.mkdir(srcFilePath),
            fs.mkdir(compiledPath)
        ]);
    
        // Old web assets from previous build
        let oldSolutionsData = [];
        try {
            oldSolutionsData = JSON.parse(await fs.readFile(path.join(previousBuildDir, 'solutions.json'), 'utf-8'));
        } catch(ignored) {}
        
        // Copy over source files
        await Promise.all(solutionsData.map(async solution => {
            try {
                await fs.mkdir(path.join(srcFilePath, solution.problemID));
            } catch(ignored) {}
            await fs.copyFile(path.join(srcDir, solution.fileName), path.join(srcFilePath, solution.problemID, solution.fileName));
        }));
        
        // Sort into new and removed items based on previous indexing json
        const existingItems = solutionsData.filter(srcData => {
            return oldSolutionsData.some(oldData => (oldData.problemID === srcData.problemID &&
                oldData.hash === srcData.hash))
        });
        const newItems = solutionsData.filter(srcData => {
            return !existingItems.some(existingData => (srcData.problemID === existingData.problemID &&
                existingData.hash === srcData.hash))
        });
        
        // Copy all existing items
        await Promise.all(existingItems.map(async existingItem => {
            await fs.copyFile(path.join(previousBuildDir, 'compiled', existingItem.problemID + '.wasm'), path.join(compiledPath, existingItem.problemID + '.wasm'));
        }));
        
        // Compile all new items
        for(const newItem of newItems) {
            const fPath = path.resolve(path.join(srcDir, newItem.fileName));
            const toPath = path.resolve(path.join(compiledPath, newItem.problemID + '.js'));
            
            console.log(`Compiling ${newItem.fileName}...`);
            const cmdData = await shellExec(`emcc -O3 -g0 -flto --closure 1 -s EXIT_RUNTIME -s ENVIRONMENT=web ${fPath} -o ${toPath}`);
            if(cmdData.stderr.length !== 0) {
                console.warn(cmdData.stderr);
            }
            
            // We don't need the JS file
            try {
                await fs.rm(toPath);
            } catch(ignored) {}
        }
    });
    
    api.loadSource(async ({addCollection}) => {
        // Use the Data Store API here: https://gridsome.org/docs/data-store-api/
    
        // Read data from cpp files
        const srcFiles = await fs.readdir(srcDir);
        const solutionsData = (await Promise.all(srcFiles.map(async fileName => {
            const srcData = await parseSrcFile(path.join(srcDir, fileName));
            if(srcData === null) return null;
            srcData.fileName = fileName;
            return srcData;
        }))).filter(srcData => srcData !== null);
        
        // Add solutions to collection
        const solutions = addCollection('Solutions');
        for(const solution of solutionsData) {
            solutions.addNode({
                id: `${solution.problemID}-${solution.fileName}`,
                ...solution
            });
        }
    })
    
    api.createPages(({ createPage }) => {
        // Use the Pages API here: https://gridsome.org/docs/pages-api/
    })
}
