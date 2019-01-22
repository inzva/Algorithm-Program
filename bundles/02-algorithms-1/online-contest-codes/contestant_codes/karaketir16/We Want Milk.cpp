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

struct compare {
    bool operator()(const pair<int, int>& value1, const pair<int, int>& value2)
    {
        return (value1.first > value2.first);
    }

};
int main() {
    int n,m;
    cin>>n>>m;
    vector<pair<lint,lint>> arr;
    for(int i=0;i<n;i++)
    {
        lint x;
        lint y;
        cin>>x>>y;
        arr.pb(MP(x,y));
    }
    sort(arr.begin(),arr.end());
    lint total=0;
    for(int i =0;m>0;i++)
    {
        if(arr[i].sc<=m)
        {
            m-=arr[i].sc;
            total+=(arr[i].sc*arr[i].fi);
        }
        else
        {
            total+=(arr[i].fi*m);
            m=0;
        }
        
    }
    cout<<total;
 
    return 0;
}
