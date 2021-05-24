// Problem https://open.kattis.com/problems/ostgotska
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

    string s;
    getline(cin,s);
    s.append(" ");
    int at=0;
    bool a=false;
    int ac=0,wc=0;
    for(char c:s){
        if(c==' '){
            if(a) ac++;
            wc++;
            a=false;
        }else if(c=='a'){
            at=1;
        }else if(c=='e'&&at==1){
            a=true;
        }else{
            at=0;
        }
    }
    if(ac/(double)wc>=0.4) cout<<"dae ae ju traeligt va";
    else cout<<"haer talar vi rikssvenska";

    return 0;
}