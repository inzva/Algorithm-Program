#include <bits/stdc++.h>

using namespace std;

typedef long long int lint;

lint gcd(lint f, lint s)
{
    if(!s) return f;
    return gcd(s, f%s);
}

int main()
{
    lint n,k;
    cin>>n>>k;
    //cout<<gcd(n,k);
    
    lint maxGcd;
    cin>>maxGcd;
    for(lint i=0;i<n-1;i++)
    {
        lint a;
        cin>>a;
        maxGcd=gcd(maxGcd,a);
    }
    lint result=0;
    for(int i=2;i*i<=maxGcd;i++)
    {
        if(maxGcd%i==0)
        {
            result = i;
            break;
        }
    }
    if(result != 0) maxGcd=result;
    cout<<((lint)((lint)k/(lint)maxGcd))*maxGcd;
    return 0;    
}