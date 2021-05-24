// Problem https://open.kattis.com/problems/tri
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

int p(int *x,char o,bool l){
    if(l) cout<<x[0]<<"="<<x[1]<<o<<x[2];
    else cout<<x[0]<<o<<x[1]<<"="<<x[2];
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x[3];
    cin>>x[0]>>x[1]>>x[2];
    for(int i=0;i<2;i++){
        if(x[(0+i)%3]+x[(1+i)%3]==x[(2+i)%3]) return p(x,'+',i==1);
        if(x[(0+i)%3]-x[(1+i)%3]==x[(2+i)%3]) return p(x,'-',i==1);
        if(x[(0+i)%3]/x[(1+i)%3]==x[(2+i)%3]) return p(x,'/',i==1);
        if(x[(0+i)%3]*x[(1+i)%3]==x[(2+i)%3]) return p(x,'*',i==1);
    }

    return 0;
}