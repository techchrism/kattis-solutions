// Problem https://open.kattis.com/problems/anewalphabet
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    unordered_map<char, string> t;
    t['a'] = "@";
    t['b'] = "8";
    t['c'] = "(";
    t['d'] = "|)";
    t['e'] = "3";
    t['f'] = "#";
    t['g'] = "6";
    t['h'] = "[-]";
    t['i'] = "|";
    t['j'] = "_|";
    t['k'] = "|<";
    t['l'] = "1";
    t['m'] = "[]\\/[]";
    t['n'] = "[]\\[]";
    t['o'] = "0";
    t['p'] = "|D";
    t['q'] = "(,)";
    t['r'] = "|Z";
    t['s'] = "$";
    t['t'] = "']['";
    t['u'] = "|_|";
    t['v'] = "\\/";
    t['w'] = "\\/\\/";
    t['x'] = "}{";
    t['y'] = "`/";
    t['z'] = "2";
    
    string s;
    getline(cin, s);
    for(char c:s){
        char l=tolower(c);
        if(t.count(l)){
            cout<<t[l];
        }else{
            cout<<c;
        }
    }

    return 0;
}