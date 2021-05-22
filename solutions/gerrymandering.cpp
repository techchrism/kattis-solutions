// Problem
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

    int p,d;
    cin>>p>>d;
    PII ds[d];
    for(int i=0;i<p;i++){
        int di,a,b;
        cin>>di>>a>>b;
        di--;
        ds[di].first+=a;
        ds[di].second+=b;
    }
    int wa=0,wb=0,t=0;
    for(int i=0;i<d;i++){
        int need=((ds[i].first+ds[i].second)/2)+1;
        t+=ds[i].first+ds[i].second;
        if(ds[i].first>ds[i].second){
            cout<<"A "<<ds[i].first-need<<" "<<ds[i].second<<"\n";
            wa+=ds[i].first-need;
            wb+=ds[i].second;
        }else{
            cout<<"B "<<ds[i].first<<" "<<ds[i].second-need<<"\n";
            wa+=ds[i].first;
            wb+=ds[i].second-need;
        }
    }
    cout<<fixed<<(abs(wa-wb)/(double)t);

    return 0;
}