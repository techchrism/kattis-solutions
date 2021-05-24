// Problem https://open.kattis.com/problems/unlockpattern
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

    pair<int, PII> p[9];
    for(int i=0;i<9;i++){
        int x;
        cin>>x;
        p[i]=MP(x,MP(i%3,i/3));
    }
    sort(p,p+9);
    PII l=p[0].second;
    double d=0.0;
    for(int i=1;i<9;i++){
        d+=sqrt(pow(abs(p[i].second.first-l.first),2)+pow(abs(p[i].second.second-l.second),2));
        l=p[i].second;
    }
    cout<<fixed<<d;

    return 0;
}