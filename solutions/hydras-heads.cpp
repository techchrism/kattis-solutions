// Problem https://open.kattis.com/problems/hydrasheads
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

    while(true){
        int h,t;
        cin>>h>>t;
        if(h==0)break;

        int s=0;
        while(h!=0||t!=0){
            s++;
            if(h%2==0){
                if(t==0){
                    h-=2;
                }else if(t%4==0){
                    s++;
                    t-=4;
                    h+=2;
                }else t++;
            }else{
                if(t>=2){
                    t-=2;
                    h++;
                }else if(t==1){
                    t++;
                }else{
                    s=-1;
                    break;
                }
            }
        }
        cout<<s<<"\n";
    }

    return 0;
}