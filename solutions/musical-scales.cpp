// Problem https://open.kattis.com/problems/musicalscales
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
    cin>>n;
    string no[]={"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"};
    SETI s;
    for(int i=0;i<n;i++){
        string ns;
        cin>>ns;
        for(int j=0;j<12;j++){
            if(ns==no[j]){
                s.insert(j);
                break;
            }
        }
    }
    bool f=false;
    for(int i=0;i<12;i++){
        int scl[]={i,i+2,i+4,i+5,i+7,i+9,i+11};
        for(int &scli:scl) scli%=12;
        bool all=true,fc=false;
        for(int si:s){
            for(int scli:scl){
                if(si==scli){
                    fc=true;
                    break;
                }
            }
            if(!fc){
                all=false;
                break;
            }
            fc=false;
        }
        if(all){
            cout<<no[i]<<" ";
            f=true;
        }
    }
    if(!f) cout<<"none";

    return 0;
}