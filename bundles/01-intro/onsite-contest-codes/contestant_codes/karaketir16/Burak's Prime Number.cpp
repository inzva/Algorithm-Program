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
        lint x;
        cin>>x;
        bool notPrime=0;
        if(x%2==0) notPrime=1;
        lint s=sqrt(x);
        for(int i=3;i<=s&&!notPrime;i+=2)
        {
            if(x%i==0) notPrime=1;
        }
        if(notPrime) cout<<"Not Prime\n";
        else cout<<"Prime\n";
    }
    return 0;
}
