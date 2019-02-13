#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define sc second
#define inf    1000000000000000LL
#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
using namespace std;
#define pp pair<int,int>

typedef long long int lint;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        int alfabe[30];
        for(int i=0;i<30;i++) alfabe[i]=0;
        for(auto x:s1)
        {
            alfabe[x-'a']++;
        }
        bool find=0;
        for(auto x:s2)
        {
            if(alfabe[x-'a']>0)
            {
                cout<<"YES\n";
                find=1;
                break;
            }
        }
        if(!find) cout<<"NO\n";
    }
    return 0;

}