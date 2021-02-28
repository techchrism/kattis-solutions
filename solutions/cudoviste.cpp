// Problem https://open.kattis.com/problems/cudoviste
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

    int r,c;
    cin>>r>>c;
    string sr[r];
    for(int i = 0; i < r;i++)
    {
        cin>>sr[i];
    }
    int ps[5]={0};
    for(int y=0;y<r-1;y++)
    {
        for(int x=0;x<c-1;x++)
        {
            int car = 0;
            for(int ys=y;ys<=y+1;ys++)
            {
                for(int xs=x;xs<=x+1;xs++)
                {
                    char ch = sr[ys][xs];
                    if(ch == '#')
                        car=-10;
                    else if(ch == 'X')
                        car++;
                }
            }
            if(car>=0)
                ps[car]+=1;
        }
    }
    for(int p : ps)
        cout<<p<<"\n";


    return 0;
}
