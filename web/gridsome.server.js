// Server API makes it possible to hook into various parts of Gridsome
// on server-side and add custom data to the GraphQL data layer.
// Learn more: https://gridsome.org/docs/server-api/

// Changes here require a server restart.
// To restart press CTRL + C in terminal and run `gridsome develop`

const fs = require('fs').promises;
const path = require('path');
const crypto = require('crypto');

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
const staticDir = path.join(__dirname, 'static');
const solutionDataPath = path.join(staticDir, 'solutions.json');

module.exports = function(api) {
    
    api.afterBuild(async ({config}) => {
        const srcFilePath = path.join(config.outputDir, 'src');
        const compiledPath = path.join(config.outputDir, 'compiled');
    
        await Promise.allSettled([
            fs.mkdir(srcFilePath),
            fs.mkdir(compiledPath)
        ]);
    
        // Old web assets from previous build
        let oldSolutionsData = [];
        try {
            oldSolutionsData = JSON.parse(await fs.readFile(solutionDataPath, 'utf-8'));
        } catch(ignored) {}
        
        // Copy over files
        
        // Sort into new and removed items based on previous indexing json
        const changedItems = solutionsData.filter(srcData => {
            return !oldSolutionsData.some(oldData => (oldData.problemID === srcData.problemID &&
                oldData.hash === srcData.hash))
        });
        const removedItems = oldSolutionsData.filter(oldData => {
            return !solutionsData.some(srcData => (srcData.problemID === oldData.problemID))
        });
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
        
        // Write file to static serve containing source meta
        await fs.writeFile(solutionDataPath, JSON.stringify(solutionsData, null, 4), 'utf-8');
        
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
