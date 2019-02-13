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

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> ata;
    for(int i=0;i<=n;i++)
    {
        ata.pb(i);
    }
    while(m--)
    {
        int t, a, b;
        scanf("%d %d %d", &t, &a, &b);
        if(t==1)//connect
        {
            while(b!=ata[b])
            {
                b=ata[b];
            }
            while(a!=ata[a])
            {
                a=ata[a];
            }
            if(a<b) ata[a]=b;
            else if(a>b) ata[b]=a;
        }
        else
        {
            while(b!=ata[b])
            {
                b=ata[b];
            }
            while(a!=ata[a])
            {
                a=ata[a];
            }
            if(a==b) cout<<"Connect\n";
            else cout<<"Not Connect\n";
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
