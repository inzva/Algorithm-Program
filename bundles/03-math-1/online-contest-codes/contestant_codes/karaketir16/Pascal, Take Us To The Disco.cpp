#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;
typedef long long lint;
lint fastPow(lint n, lint k)
{
    if(k==0) return 1;
    if(k==1) return n%mod;
    lint temp=fastPow(n,k>>1)%mod;
    if(k&1) return (temp*temp*n)%mod;
    return (temp*temp)%mod;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        lint n;
        cin>>n;
        cout<<fastPow(2,n)-1<<"\n";        
    }
    return 0;
}
