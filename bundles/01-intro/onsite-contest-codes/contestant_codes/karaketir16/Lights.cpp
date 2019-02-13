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

typedef long long int ll;
void fonk(bool street[], int k, int x, int n)
{
    for(int i=x-k;i<=x+k;i++)
    {
        if(i>0&&i<=n)
        {
            street[i]=1;
        }
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    int total=0;
    bool street[1005];
    for(int i=0;i<1005;i++) street[i]=0;

    while(m--)
    {
        int x;
        cin>>x;
        for(int i=x-k;i<=x+k;i++)
        {
            if(i>0&&i<=n)
            {
                street[i]=1;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(street[i]==0)
        {
            fonk(street, k, i+k,n);
            total++;

        }
    }
    cout<<total;
    return 0;
}