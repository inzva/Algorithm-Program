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
    cin>>m;
    map<int,int> arr;
    map<int,int> indicates;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[x]++;
        indicates[x]=i+1;
    }

    for(int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if(arr[x]==1) cout<<indicates[x]<<'\n';
        else cout<<"-1\n";
    }


    return 0;
}