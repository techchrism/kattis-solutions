// Problem https://open.kattis.com/problems/cetvrta
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

    int x[3];
    int y[3];
    for(int i=0;i<3;i++)
    {
        cin>>x[i];
        cin>>y[i];
    }
    sort(x,x+3);
    sort(y,y+3);
    int ux,uy;
    for(int i=0;i<3;i++)
    {
        if(x[i]==x[i+1])
            i++;
        else
            ux=x[i];
    }
    for(int i=0;i<3;i++)
    {
        if(y[i]==y[i+1])
            i++;
        else
            uy=y[i];
    }
    cout<<ux<<" "<<uy;

    return 0;
}
