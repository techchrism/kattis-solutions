// Problem https://open.kattis.com/problems/prva
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

    int r,c;
    cin>>r>>c;
    string g[r];
    VS w;
    for(int i=0;i<r;i++){
        cin>>g[i];

        string b;
        for(int j=0;j<=c;j++){
            if(j==c||g[i][j]=='#'){
                if(b.size()>=2)w.PB(b);
                b="";
            }else{
                b+=g[i][j];
            }
        }
    }

    string b;
    for(int i=0;i<c;i++) {
        for(int j=0;j<=r;j++) {
            if(j==r||g[j][i]=='#') {
                if(b.size()>=2)w.PB(b);
                b="";
            }else{
                b+=g[j][i];
            }
        }
    }

    sort(w.begin(),w.end());
    cout<<w[0];

    return 0;
}