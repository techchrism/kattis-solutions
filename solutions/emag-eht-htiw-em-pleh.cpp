// Problem https://open.kattis.com/problems/empleh
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

struct piece
{
    char c;
    int x,y;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<piece> ps;
    for(int i=0;i<2;i++){
        string s;
        getline(cin,s);
        for(int j=7;j<s.size();){
            piece p;
            int l=(j+2!=s.size()&&s[j+2]!=',');
            p.c=l?s[j]:'P';
            p.x=s[j+l]-'a';
            p.y=7-((s[j+l+1]-'0')-1);
            if(i==1) p.c=tolower(p.c);
            ps.PB(p);
            j+=3+l;
        }
    }

    for(int y=0;y<8;y++){
        cout<<"+---+---+---+---+---+---+---+---+\n";
        for(int x=0;x<8;x++){
            char c=(x+y)%2==0?'.':':';
            cout<<"|"<<c;
            bool f=false;
            for(auto p:ps){
                if(p.x==x&&p.y==y){
                    cout<<p.c;
                    f=true;
                    break;
                }
            }
            if(!f) cout<<c;
            cout<<c;
        }
        cout<<"|\n";
    }
    cout<<"+---+---+---+---+---+---+---+---+\n";

    return 0;
}