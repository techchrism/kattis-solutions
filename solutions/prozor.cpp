// Problem https://open.kattis.com/problems/prozor
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

    int r,s,k;
    cin>>r>>s>>k;
    VII f;
    for(int i=0;i<r;i++){
        string l;
        cin>>l;
        for(int j=0;j<s;j++){
            if(l[j]=='*') f.PB(MP(i,j));
        }
    }
    int x,y,t=0;
    for(int i=0;i<=r-k;i++){
        for(int j=0;j<=s-k;j++){
            int fc=0;
            for(auto fly:f){
                if(fly.first>i&&fly.first<(i+k-1) &&
                    fly.second>j&&fly.second<(j+k-1)){
                    fc++;
                }
            }
            if(fc>t){
                t=fc;
                x=j;
                y=i;
            }
        }
    }
    cout<<t<<"\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<s;j++){
            if((x==j&&y==i)||(x==j-k+1&&y==i)||(x==j&&y==i-k+1)||(x==j-k+1&&y==i-k+1)) cout<<"+";
            else if((x==j||x==j-k+1)&&(i>y&&i<y+k)) cout<<"|";
            else if((y==i||y==i-k+1)&&(j>x&&j<x+k)) cout<<"-";
            else {
                bool ff=false;
                for(auto fly:f){
                    if(fly.first==i&&fly.second==j){
                        ff=true;
                        cout<<"*";
                    }
                }
                if(!ff) cout<<".";
            }
        }
        cout<<"\n";
    }

    return 0;
}