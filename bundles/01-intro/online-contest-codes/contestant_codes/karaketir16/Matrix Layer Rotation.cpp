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
const int MAX=305;
int matrix[MAX][MAX];
int shifted[MAX][MAX];
int main()
{
    int m,n,r;
    cin>>n>>m>>r;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    if(n<=m)
    {
        
        for(int i=0 ;i<n/2; i++)
        {
            int yatay=0;
            int dikey=0;
            yatay = m-2*i;
            dikey= n-2*i;
            int cevre=yatay*2+dikey*2-4;
            vector<pair<int,int>> vp;
            for(int k=i;k<(n-i)-1;k++)
            {
                vp.pb(MP(k,i));
            }
            for(int k=i,l=(n-i)-1;k<(m-i)-1;k++)
            {
                vp.pb(MP(l,k));
            }
            for(int k=(n-1)-i,l=(m-i)-1;k>i;k--)
            {
                vp.pb(MP(k,l));
            }
            for(int k=(m-i)-1;k>i;k--)
            {
                vp.pb(MP(i,k));
            }
            for(int p=0;p<cevre;p++)
            {
                auto t = vp[p];
                int y =t.fi;
                int x =t.sc;
                int sayi=matrix[y][x];
                int gidecek=(p+r)%cevre;
                t=vp[gidecek];
                y=t.fi;
                x=t.sc;
                shifted[y][x]=sayi;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<shifted[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        
        for(int i=0 ;i<m/2; i++)
        {
            int yatay=0;
            int dikey=0;
            yatay = m-2*i;
            dikey= n-2*i;
            int cevre=yatay*2+dikey*2-4;
            vector<pair<int,int>> vp;
            for(int k=i;k<(n-i)-1;k++)
            {
                vp.pb(MP(k,i));
            }
            for(int k=i,l=(n-i)-1;k<(m-i)-1;k++)
            {
                vp.pb(MP(l,k));
            }
            for(int k=(n-1)-i,l=(m-i)-1;k>i;k--)
            {
                vp.pb(MP(k,l));
            }
            for(int k=(m-i)-1;k>i;k--)
            {
                vp.pb(MP(i,k));
            }
            for(int p=0;p<cevre;p++)
            {
                auto t = vp[p];
                int y =t.fi;
                int x =t.sc;
                int sayi=matrix[y][x];
                int gidecek=(p+r)%cevre;
                t=vp[gidecek];
                y=t.fi;
                x=t.sc;
                shifted[y][x]=sayi;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<shifted[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}