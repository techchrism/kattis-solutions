// Problem https://open.kattis.com/problems/pokerhand
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

    map<char, int> cards = {
            {'A',0},
            {'2',1},
            {'3',2},
            {'4',3},
            {'5',4},
            {'6',5},
            {'7',6},
            {'8',7},
            {'9',8},
            {'T',9},
            {'J',10},
            {'K',11},
            {'Q',12},
    };
    int c[13] = {0};
    int m = 0;
    for(int i = 0; i < 5; i++)
    {
        string s;
        cin>>s;
        c[cards[s[0]]]++;
        m = max(m, c[cards[s[0]]]);
    }
    cout << m;

    return 0;
}
