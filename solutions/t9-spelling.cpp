// Problem https://open.kattis.com/problems/t9spelling
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    map<string, char> k = {
            {"abc", '2'},
            {"def", '3'},
            {"ghi", '4'},
            {"jkl", '5'},
            {"mno", '6'},
            {"pqrs", '7'},
            {"tuv", '8'},
            {"wxyz", '9'},
            {" ", '0'}
    };
    char l;
    for(int i=0;i<n;i++)
    {
        l='\0';
        cout<<"Case #"<<(i+1)<<": ";
        string s;
        getline(cin,s);
        for(char c:s)
        {
            for(pair<string,char> p:k)
            {
                int pos=p.first.find(c);
                if(pos!=string::npos)
                {
                    if(p.second==l)
                        cout<<" ";
                    for(int j=0;j<pos+1;j++)
                        cout<<p.second;
                    l=p.second;
                    break;
                }
            }
        }
        cout<<"\n";
    }

    return 0;
}
