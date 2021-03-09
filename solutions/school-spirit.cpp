// Problem https://open.kattis.com/problems/schoolspirit
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

double calc(double *vals, int length, int skip) {
    double r = 0.0;
    int i = 0;
    for(int j=0;j<length;j++) {
        if(j==skip)
            continue;
        r+=(pow(0.8,i)*vals[j]);
        i++;
    }
    r *= 0.2;
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    double s[n];
    for(int i = 0;i<n;i++)
        cin>>s[i];


    double t = 0;
    for(int i = 0; i < n;i++) {
        t+=calc(s,n,i);
    }
    t/=(double)n;
    cout<<fixed<<calc(s,n,-1)<<"\n"<<t;

    return 0;
}