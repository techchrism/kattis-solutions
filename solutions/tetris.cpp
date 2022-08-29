// Problem https://open.kattis.com/problems/tetris
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

    VVI om[7]={
            {{},{0,0,0}},
            {{0}},
            {{0,1},{-1}},
            {{-1,-1},{1}},
            {{0,0},{1},{-1,0},{-1}},
            {{0,0},{-2},{1,1},{0}},
            {{0,0},{0},{0,-1},{2}}
    };

    int c,p,t=0;
    cin>>c>>p;
    int b[c];
    for(int i=0;i<c;i++){
        cin>>b[i];
    }
    VVI uo=om[p-1];
    for(int i=0;i<c;i++){
        for(VI o:uo){
            if(o.size()+i+1>c)continue;
            bool f=true;
            for(int j=0;j<o.size();j++){
                if(b[i+j+1]-b[i]!=o[j]){
                    f=false;
                    break;
                }
            }
            if(f)t++;
        }
    }
    cout<<t;

    return 0;
}