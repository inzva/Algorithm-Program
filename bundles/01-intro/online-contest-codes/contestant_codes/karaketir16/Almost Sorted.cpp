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
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.pb(x);
    }
    if(is_sorted(v.begin(),v.end()))
    {
        cout<<"yes";
        return 0;
    }
    int i=0;
    for(i=1;i<n;i++)
    {
        if(v[i-1]>v[i]) break;
    }
    int j=0;
    for(j=n-2;j>1;j--)
    {
        if(v[j+1]<v[j]) break;
    }
    if(j==i)
    {
        cout<<"no";
        return 0;
    }
    i--;
    j++;
    swap(v[i],v[j]);
    //cout<<i<<" "<<j<<endl;
    if(is_sorted(v.begin(),v.end()))
    {
        cout<<"yes\nswap "<<i+1<<" "<<j+1;
        return 0;
    }
    int old_i=i;
    int old_j=j;
    i++;
    j--;
    while(i<j)
    {
        swap(v[i],v[j]);
        i++;
        j--;
    }
    if(is_sorted(v.begin(),v.end()))
    {
        cout<<"yes\nreverse "<<old_i+1<<" "<<old_j+1;
        return 0;
    }
    /*
    for(auto e:v)
    {
        cout<<e<<" ";
    }
    */
    cout<<"no";

    return 0;
}