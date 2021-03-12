// Problem https://open.kattis.com/problems/racingalphabet
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
    cin>>n;
    cin.ignore();
    double cir=60.0*PI;
    double tick=cir/28.0;
    for(int i=0;i<n;i++) {
        string s;
        getline(cin,s);
        double t=0.0;
        int p=-1;
        for(char c:s) {
            int y;
            if(c >= 'A' && c <= 'Z')
                y=(c-'A');
            else if(c==' ')
                y=26;
            else if(c=='\'')
                y=27;
            if(p!=-1)
                t+=min(min(abs(p-y),abs(p-(y-28))),abs((p-28)-y))*tick;
            p=y;
        }
        t/=15.0;
        t+=s.length();
        cout<<fixed<<t<<"\n";
    }

    return 0;
}