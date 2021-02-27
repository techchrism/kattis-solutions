// Problem https://open.kattis.com/problems/drmmessages
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

void rotate(string &str)
{
    int t=0;
    for(char c : str)
    {
        t += ((int)c) - 65;
    }
    for(char & i : str)
    {
        i = ((t+(i-65))%26)+65;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string m;
    cin>>m;
    string p1,p2;
    p1=m.substr(0,m.size()/2);
    p2=m.substr(m.size()/2,string::npos);
    rotate(p1);
    rotate(p2);
    for(int i = 0; i < p1.length(); i++)
    {
        p1[i] = ((p1[i]-65+p2[i]-65)%26)+65;
    }
    cout << p1;
    return 0;
}
