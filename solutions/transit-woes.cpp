// Problem https://open.kattis.com/problems/transitwoes
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

    int s,t,n;
    cin >> s >> t >> n;
    int walk[n + 1];
    int btime[n];
    int binterval[n];
    for(int i = 0; i < n + 1; i++)
    {
        cin >> walk[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> btime[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> binterval[i];
    }

    int time = s + walk[0];
    for(int i = 0; i < n; i++)
    {
        while((time % binterval[i]) != 0)
        {
            time++;
        }
        time += btime[i] + walk[i + 1];
    }

    if(time > t)
    {
        cout << "no";
    }
    else
    {
        cout << "yes";
    }


    return 0;
}
