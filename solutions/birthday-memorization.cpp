// Problem https://open.kattis.com/problems/fodelsedagsmemorisering
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
#include <unordered_map>

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

struct f {
    string n;
    int p;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    unordered_map<string,f> fm;
    cin>>n;
    for(int i=0;i<n;i++){
        f fr;
        string s;
        cin>>fr.n>>fr.p>>s;

        auto it = fm.find(s);
        if(it == fm.end() || fr.p>it->second.p){
            fm[s]=fr;
        }
    }
    cout<<fm.size()<<"\n";
    VS k;
    for(auto fp:fm){
        k.PB(fp.second.n);
    }
    sort(k.begin(), k.end());
    for(auto n:k){
        cout<<n<<"\n";
    }

    return 0;
}