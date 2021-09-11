// Problem https://open.kattis.com/problems/coconut
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

    int s,n;
    cin>>s>>n;
    PII h[n];
    for(int i=0;i<n;i++) h[i]=MP(0,0);
    int p=-1,syl=0;
    while(true){
        p++;
        if(p==n) p=0;

        if(h[p].first==3&&h[p].second==3){
            continue;
        }

        // Right
        if(h[p].first!=3){
            syl++;
            if(syl==s){
                syl=0;
                if(h[p].first==0&&h[p].second==0){
                    h[p].first=1;
                    h[p].second=1;
                    p--;
                    continue;
                }else{
                    h[p].first++;
                }
            }
        }

        // Left
        if(h[p].second!=3&&!(h[p].first==0&&h[p].second==0)){
            syl++;
            if(syl==s){
                syl = 0;
                h[p].second++;
            }
        }

        if(h[p].first==3&&h[p].second==3){
            int lastPos=-1;
            for(int j=0;j<n;j++){
                if(!(h[j].first==3&&h[j].second==3)){
                    if(lastPos==-1){
                        lastPos=j;
                    }else{
                        lastPos=-2;
                    }
                }
            }
            if(lastPos!=-2){
                cout<<(lastPos+1);
                return 0;
            }
        }
    }
}