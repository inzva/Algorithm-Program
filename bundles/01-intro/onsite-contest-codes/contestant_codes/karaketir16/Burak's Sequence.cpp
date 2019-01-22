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
    int n;
    cin>>n;
    lint arrB[105];
    lint arrA[105];
    arrB[0]=0;
    arrA[0]=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>arrB[i];
    }
    for(int i=1;i<=n;i++)
    {
        lint tot_now = arrB[i]*i;
        lint tot_pre = arrB[i-1]*(i-1);
        lint numb= tot_now-tot_pre;
        arrA[i]=numb;
    }

    for(int i=1;i<=n;i++) cout<<arrA[i]<<" ";
    return 0;
    



}