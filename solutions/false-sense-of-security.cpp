// Problem https://open.kattis.com/problems/falsesecurity
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

    string m[30]={
            ".-","-...","-.-.","-..",".","..-.","--.",
            "....","..",".---","-.-",".-..","--","-.",
            "---",".--.","--.-",".-.","...","-","..-",
            "...-",".--","-..-","-.--","--..",
            "..--",".-.-","---.","----"
    };
    string s="_,.?";

    string l;
    while(getline(cin,l)){
        if(l.empty())break;
        int len[l.size()];
        string e;
        for(int i=0;i<l.size();i++){
            int in=l[i]-'A';
            if(in<0||in>25)in=s.find(l[i])+26;
            len[i]=m[in].size();
            e+=m[in];
        }
        reverse(len,len+l.size());
        int c=0;
        for(int i=0;i<l.size();i++){
            string ec=e.substr(c,len[i]);
            c+=len[i];
            int it=find(m,m+30,ec)-m;
            cout<<(char)(it>25?s[it-26]:it+'A');
        }
        cout<<"\n";
    }

    return 0;
}