// Problem https://open.kattis.com/problems/bela
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
    char dom;
    cin >> n >> dom;

    map<char, int> sdom;
    sdom.insert(MP('A', 11));
    sdom.insert(MP('K', 4));
    sdom.insert(MP('Q', 3));
    sdom.insert(MP('J', 20));
    sdom.insert(MP('T', 10));
    sdom.insert(MP('9', 14));
    map<char, int> sndom;
    sndom.insert(MP('A', 11));
    sndom.insert(MP('K', 4));
    sndom.insert(MP('Q', 3));
    sndom.insert(MP('J', 2));
    sndom.insert(MP('T', 10));

    int score = 0;
    for(int i = 0; i < 4*n; i++)
    {
        string h;
        cin >> h;
        if(h[1] == dom)
        {
            if(sdom.count(h[0]) == 1) score += sdom[h[0]];
        }
        else
        {
            if(sndom.count(h[0]) == 1) score += sndom[h[0]];
        }
    }
    cout << score;

    return 0;
}
