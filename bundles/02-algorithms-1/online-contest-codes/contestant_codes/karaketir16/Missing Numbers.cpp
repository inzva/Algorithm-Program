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
    int n,m;
    cin>>n;
    vector<int> arr(200005,0),brr(200005,0);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[x]++;
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        brr[x]++;
    }

    for(int i=0;i<200005;i++)
    {
        if(arr[i]!=brr[i]) cout<<i<<' ';
    }

    return 0;
}