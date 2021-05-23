// Problem https://open.kattis.com/problems/closingtheloop
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        VI r,b;
        for(int j=0;j<s;j++){
            int l;
            char c;
            cin>>l>>c;
            if(c=='B') b.PB(l);
            else r.PB(l);
        }
        cout<<"Case #"<<(i+1)<<": ";
        int m=min(r.size(),b.size());
        if(m==0){
            cout<<"0\n";
            continue;
        }
        sort(r.begin(),r.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        int t=0;
        for(int j=0;j<m;j++){
            t+=r[j]+b[j];
        }
        cout<<(t-(m*2))<<"\n";
    }


    return 0;
}