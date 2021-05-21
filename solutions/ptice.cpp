// Problem https://open.kattis.com/problems/ptice
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
    string s;
    cin>>n>>s;
    int a=0,b=0,g=0;
    for(int i=0;i<n;i++){
        if(s[i]=="ABC"[i%3]) a++;
        if(s[i]=="BABC"[i%4]) b++;
        if(s[i]=="CCAABB"[i%6]) g++;
    }
    int l=max(max(a,b),g);
    cout<<l<<"\n";
    if(a==l) cout<<"Adrian\n";
    if(b==l) cout<<"Bruno\n";
    if(g==l) cout<<"Goran\n";

    return 0;
}