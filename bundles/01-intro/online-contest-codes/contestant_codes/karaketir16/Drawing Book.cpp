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
    int n,p;
    cin>>n>>p;
    int block_sayisi=(n/2)+1;
    int istenen=(p/2)+1;
    cout<<min(istenen-1,block_sayisi-istenen);
    return 0;
}