// Problem https://open.kattis.com/problems/hittingtargets
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

struct Target {
    int x1,y1,x2,y2;
    int x,y,r;
    bool rect;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin>>n;
    vector<Target> tg;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        Target t;
        t.rect=(s=="rectangle");
        if(t.rect) cin>>t.x1>>t.y1>>t.x2>>t.y2;
        else cin>>t.x>>t.y>>t.r;
        tg.PB(t);
    }
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        int h=0;
        for(auto t:tg){
            if(t.rect){
                if(x>=t.x1&&x<=t.x2&&y>=t.y1&&y<=t.y2) h++;
            }else{
                if(pow(x-t.x,2)+pow(y-t.y,2)<=pow(t.r,2)) h++;
            }
        }
        cout<<h<<"\n";
    }

    return 0;
}