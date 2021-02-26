// Problem https://open.kattis.com/problems/heimavinna
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

int amount(string part)
{
    int cpos = part.find("-");
    if(cpos == string::npos)
    {
        return 1;
    }
    else
    {
        int first = stoi(part.substr(0, cpos));
        part.erase(0, cpos + 1);
        int second = stoi(part);
        return (second - first) + 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    string t;
    int p = 0;
    int total = 0;
    while((p = s.find(";")) != string::npos)
    {
        t = s.substr(0, p);
        total += amount(t);
        s.erase(0, p + 1);
    }
    total += amount(s);

    cout << total;

    return 0;
}
