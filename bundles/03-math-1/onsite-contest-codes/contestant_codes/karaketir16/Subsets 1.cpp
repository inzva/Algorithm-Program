#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;
typedef long long int lint;
lint poww(lint x)
{
    if(!x) return 1;
    lint temp=(poww(x>>1)*poww(x>>1))%mod;
    if(x&1) return (temp*2)%mod;
    else return temp;
}
int main() {
    lint n,t;
    cin>>n;
    t=n;
    lint result;
    while(t--)
    {
        //cout<<poww(t)<<endl;
        lint x;
        cin>>x;
        x%=mod;
        result+=x;
        result%=mod;
    }
    cout<<(poww(n-1)*result)%mod;
    
    return 0;
}
