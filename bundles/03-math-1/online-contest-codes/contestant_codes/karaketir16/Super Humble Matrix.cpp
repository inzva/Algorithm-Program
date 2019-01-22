#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;


typedef long long int lint;
int main()
{
    lint facts[1000005];
    facts[0]=1;
    for(int i=1;i<1000005;i++)
    {
        facts[i]=(facts[i-1]*i)%mod;    
    }
    int k,l;
    cin>>k>>l;
    int n,m;
    n=min(k,l);
    m=max(k,l);
    lint result=1;
    for(int i=1;i<=m;i++)
    {
        if(i<n) result=(result*=((facts[i]*facts[i])%mod))%mod;
        else result=(result*=(facts[n]%mod))%mod;
    }
    cout<<result;
    return 0;
}