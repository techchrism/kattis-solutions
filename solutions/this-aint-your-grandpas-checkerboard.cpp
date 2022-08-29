// Problem https://open.kattis.com/problems/thisaintyourgrandpascheckerboard
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

using namespace std;

#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    bool b[n][n];
    bool br[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            bool v=(c=='W');
            b[i][j]=br[j][i]=v;
        }
    }

    for(int i=0;i<n;i++){
        bool* ca[2]={b[i],br[i]};
        for(auto c:ca){
            int tc=count(c,c+n,true);
            for(int j=0;j<n-2;j++){
                if((c[j]==c[j+1]&&c[j+1]==c[j+2])||tc!=n/2){
                    cout<<0;
                    return 0;
                }
            }
        }
    }
    cout<<1;

    return 0;
}