// Problem https://open.kattis.com/problems/convexpolygonarea
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
    for(int i=0;i<n;i++){
        int pc;
        cin>>pc;
        VII p;
        for(int j=0;j<pc;j++){
            PII pi;
            cin>>pi.first>>pi.second;
            p.PB(pi);
        }
        vector<pair<PII,PII>> s;
        for(int j=0;j<pc-1;j++){
            s.PB(MP(p[j],p[j+1]));
        }
        s.PB(MP(p[pc-1],p[0]));

        int t=0;
        for(auto si:s){
            t+=(si.first.first*si.second.second)-(si.first.second*si.second.first);
        }
        cout<<abs(t*0.5)<<"\n";
    }

    return 0;
}