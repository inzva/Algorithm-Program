#include <bits/stdc++.h>
#define pb push_back
#define mod 1000000007
using namespace std;
typedef long long int lint;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        vector<int> v;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.pb(x);
        }
        sort(v.begin(),v.end());
        lint result = 1;
        bool possible=1;
        for(int i=1;i<=n;i++)
        {
            result*=((i-v[i-1])%mod);
            result=(result%mod);
            if((i-v[i-1])<=0) 
            {
                possible=0;
                break;
            }
        }
        if(possible) cout<<result%mod<<'\n';
        else cout<<0<<'\n';
    }
    return 0;
}
