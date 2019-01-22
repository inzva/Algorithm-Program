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
lint arr[25];
lint minn;
void fonk(int i, int n, lint total, int dahil)
{
    if(i>n)
    {
        //cout<<total<<" "<<dahil<<endl;
        if(dahil>0) minn=min(abs(total),minn);
        return;
    }
    fonk(i+1,n,total, dahil);
    dahil++;
    fonk(i+1,n,total+arr[i],dahil);

}
int main()
{
    int n;
    cin>>n;

    arr[0]=0;
    for(int i=1;i<=n;i++) cin>>arr[i];

    //for(int i=1;i<=n;i++) arr[i]+=arr[i-1];

    minn=abs(arr[1]);

    fonk(1,n,0,0);
    cout<<minn;
    return 0;
}