// Problem https://open.kattis.com/problems/baconeggsandspam
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

    int n;
    while(true){
        cin>>n;
        if(n==0)break;
        map<string,set<string>> m;
        for(int i=0;i<n;i++){
            string s;
            getline(cin>>ws,s);
            size_t p;
            string f;
            while((p=s.find(' '))!=s.npos){
                string a=s.substr(0,p);
                if(f=="")f=a;
                else m[a].insert(f);
                s.erase(0,p+1);
            }
            m[s].insert(f);
        }
        for(auto p:m){
            cout<<p.first;
            for(auto s:p.second){
                cout<<" "<<s;
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    return 0;
}