// Problem https://open.kattis.com/problems/trik
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

    string m;
    cin >> m;
    int p[] = {1,0,0};
    for(char c : m)
    {
        if(c == 'A')
            swap(p[0], p[1]);
        else if(c == 'B')
            swap(p[1], p[2]);
        else if(c == 'C')
            swap(p[0], p[2]);
    }
    for(int i = 0; i < 3; i++)
    {
        if(p[i] == 1)
        {
            cout << (i + 1);
        }
    }

    return 0;
}
