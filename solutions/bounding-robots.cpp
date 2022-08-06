// Problem https://open.kattis.com/problems/boundingrobots
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
        int w,l,n,m;
        cin>>w>>l;
        if(w==0)break;
        cin>>n;
        int x=0,y=0,rx=0,ry=0;
        for(int i=0;i<n;i++){
            char c;
            cin>>c>>m;
            if(c=='u'||c=='d'){
                m*=(c=='u'?1:-1);
                y+=m;
                ry=min(max(ry+m,0),l-1);
            } else if(c=='r'||c=='l'){
                m*=(c=='r'?1:-1);
                x+=m;
                rx=min(max(rx+m,0),w-1);
            }
        }
        cout<<"Robot thinks "<<x<<" "<<y<<"\n";
        cout<<"Actually at "<<rx<<" "<<ry<<"\n\n";
    }

    return 0;
}