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
typedef long long int lint;
int main()
{
    int n,x,a;
    cin>>n>>x>>a;
    n--;
    if(n==0)
    {
        cout<<0;
        return 0;
    }
    x-=a;
    if(x<0)
    {
        cout<<n*1440;
        return 0;
    }
    double daily=(double)x/n;
    double sleep = a - daily;
    cout<<(int)sleep<<endl;
    return 0;
}
