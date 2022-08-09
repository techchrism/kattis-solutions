// Problem https://open.kattis.com/problems/cutinline
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,c;
    cin>>n;
    VS l;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        l.PB(s);
    }
    cin>>c;
    for(int i=0;i<c;i++){
        string a;
        cin>>a;
        if(a=="cut"){
            string f,s;
            cin>>f>>s;
            l.insert(find(l.begin(),l.end(),s),f);
        }else{
            string s;
            cin>>s;
            l.erase(find(l.begin(),l.end(),s));
        }
    }
    for(auto s:l)cout<<s<<"\n";

    return 0;
}