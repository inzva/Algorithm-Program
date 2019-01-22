#include <bits/stdc++.h>
#define mod 1000000000
using namespace std;
typedef long long int lint;

// Complete the solve function below.
lint matris [1005][1005];
void fill()
{
    for(int i=0;i<1005;i++)
    {
        for(int j=0;j<1005;j++)
        {
            matris[i][j]==0;
        }
    }
}
lint solve(lint n, lint r) 
{
    if(matris[n][r]) return matris[n][r];
    if(n==1||n==r||r==0) return matris[n][r]=1;
    return matris[n][r]=(solve(n-1,r)+solve(n-1,r-1))%mod;
}

int main()
{
    fill();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<=n;i++)
        {
            cout<<solve(n,i)<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
