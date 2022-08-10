// Problem https://open.kattis.com/problems/hidingplaces
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

    VII offset={MP(1,2),MP(-1,2),
                MP(2,1),MP(2,-1),
                MP(-2,1),MP(-2,-1),
                MP(-1,-2),MP(1,-2)};

    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char c,r;
        cin>>c>>r;
        c-='a';
        r-='1';
        VII prev;
        prev.PB(MP(r,c));
        int d=0;
        bool v[8][8]={};
        while(true){
            VII next;
            for(auto xy:prev){
                for(auto o:offset){
                    int x=xy.first+o.first,y=xy.second+o.second;
                    if(x>=0&&x<8&&y>=0&&y<8&&!v[x][y]){
                        next.PB(MP(x,y));
                        v[x][y]=true;
                    }
                }
            }
            if(next.empty()){
                cout<<d;
                sort(prev.begin(),prev.end(),[](PII l,PII r){return (l.first==r.first)?l.second<r.second:l.first>r.first;});
                for(auto xy:prev){
                    cout<<" "<<(char)(xy.second+'a')<<xy.first+1;
                }
                cout<<"\n";
                break;
            }else{
                d++;
                prev=next;
            }
        }
    }

    return 0;
}