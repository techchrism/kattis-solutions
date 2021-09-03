// Problem https://open.kattis.com/problems/helpme
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

string type="KQRBNPkqrbnp";

struct piece {
    char c;
    int x,y;

    void print()
    {
        if(c!='p'&&c!='P') cout<<(char)toupper(c);
        cout<<(char)('a'+x)<<(y+1);
    }

    bool operator < (const piece& p) const
    {
        if(c!=p.c) return type.find(toupper(c))<type.find(toupper(p.c));
        if(y!=p.y){
            if(type.find(c)<6) return y<p.y;
            return y>p.y;
        }
        return x<p.x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<piece> w,b;

    for(int i=0;i<8;i++){
        string s;
        cin>>s>>s;
        for(int j=2;j<s.length();j+=4){
            piece p{
                s[j],
                (j-2)/4,
                7-i
            };
            int pos=type.find(p.c);
            if(pos==string::npos) continue;
            if(pos<6) w.PB(p);
            else b.PB(p);
        }
    }

    sort(w.begin(),w.end());
    sort(b.begin(),b.end());

    cout<<"White: ";
    for(int i=0;i<w.size();i++){
        w[i].print();
        if(i!=w.size()-1)cout<<",";
    }
    cout<<"\nBlack: ";
    for(int i=0;i<b.size();i++){
        b[i].print();
        if(i!=b.size()-1)cout<<",";
    }

    return 0;
}