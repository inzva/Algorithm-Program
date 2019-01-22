#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define mod 1000000007
using namespace std;
typedef long long int lint;
struct Matris{
    lint u1=1;
    lint u2=1;
    lint a1=1;
    lint a2=0;
    Matris operator * (Matris m)
    {
        Matris r;
        r.u1=(this->u1*m.u1)%mod+(this->u2*m.a1)%mod;
        r.u2=(this->u1*m.u2)%mod+(this->u2*m.a2)%mod;
        r.a1=(this->a1*m.u1)%mod+(this->a2*m.a1)%mod;
        r.a2=(this->a1*m.u2)%mod+(this->a2*m.a2)%mod;
        return r;
    }
    Matris powM(lint p)
    {
        if(p==0)
        {
            this->u1=1;
            return *this;
        }
        if(p==1) return *this;
        Matris temp=this->powM(p>>1);
        if(p&1)
        {
            return temp*temp*(*this);
        }
        else
        {
            return temp*temp;
        }
    }
};
string isPrime(lint k)
{
    for(int i=2;i*i<=k;i++)
    {
        if(k%i==0) return "Not Prime";
    }
    return "Prime";
}
int main() {
    int t;
    Matris k;
    cin>>t;
    while(t--)
    {
        lint n;
        Matris m;
        cin>>n;
        cout<<isPrime(m.powM(n-1).u1%mod)<<'\n';                
    }

    return 0;
}
