// Problem https://open.kattis.com/problems/hangman
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

    string w,p;
    cin>>w>>p;
    int e=0;
    int r=w.length();
    for(char c:p){
        int rem=0;
        for(char ch:w){
            if(ch==c) {
                rem++;
            }
        }
        r-=rem;
        if(rem==0) {
            e++;
            if(e==10) {
                cout<<"LOSE";
                return 0;
            }
        }
        if(r==0) {
            cout<<"WIN";
            return 0;
        }
    }
    return 0;
}