// Problem https://open.kattis.com/problems/acm
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

    map<char,PII> ans;
    while(true)
    {
        int m;
        cin>>m;
        if(m==-1)
            break;
        char c;
        string s;
        cin>>c>>s;
        if(ans.find(c)==ans.end())
            ans.insert(MP(c, MP(s=="wrong"?1:0,s=="right"?m:-1)));
        else
        {
            if(s=="wrong")
                ans[c].first++;
            else
                ans[c].second=m;
        }
    }

    int r=0,t=0;
    for(auto a:ans)
    {
        if(a.second.second!=-1)
        {
            r++;
            t+=a.second.second+(20*a.second.first);
        }
    }
    cout<<r<<" "<<t;

    return 0;
}
