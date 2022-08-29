// Problem https://open.kattis.com/problems/flowlayout
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

    while(true){
        int m;
        cin>>m;
        if(m==0)break;
        VII b;
        while(true){
            int x,y;
            cin>>x>>y;
            if(x==-1)break;
            b.PB(MP(x,y));
        }
        int w=0,h=0,x=0,y=0;
        for(auto bx:b){
            if(x+bx.first>m){
                h+=y;
                w=max(w,x);
                x=y=0;
            }
            y=max(y,bx.second);
            x+=bx.first;
        }
        h+=y;
        w=max(w,x);
        cout<<w<<" x "<<h<<"\n";
    }

    return 0;
}