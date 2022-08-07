// Problem https://open.kattis.com/problems/bestrelayteam
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

struct r{
    string s;
    double a,b;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    vector<r> vr;
    vector<r> vrf;
    for(int i=0;i<n;i++){
        r c;
        cin>>c.s>>c.a>>c.b;
        vr.PB(c);
        vrf.PB(c);
    }
    sort(vr.begin(), vr.end(), [](r a,r b){return a.b<b.b;});
    sort(vrf.begin(), vrf.end(), [](r a,r b){return a.a<b.a;});
    double best=-1;
    int fp=-1;
    for(int i=0;i<(vrf.size()>4?5:4);i++){
        r f=vrf[i];
        double t=f.a;
        for(int j=0,c=0;c<3;j++){
            if(vr[j].s==f.s) continue;
            t+=vr[j].b;
            c++;
        }
        if(t<best||best==-1){
            best=t;
            fp=i;
        }
    }
    cout<<best<<"\n";
    cout<<vrf[fp].s<<"\n";
    for(int j=0,c=0;c<3;j++){
        if(vr[j].s==vrf[fp].s) continue;
        cout<<vr[j].s<<"\n";
        c++;
    }

    return 0;
}