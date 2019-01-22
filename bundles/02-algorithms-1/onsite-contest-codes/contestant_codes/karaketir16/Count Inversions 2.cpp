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
    vector<int> s;
    int n;
    cin>>n;
    lint total=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        auto it = upper_bound(s.begin(),s.end(),x);
        int r=it-s.begin();
        total+=(i-r);
        s.insert(it,x);
    }
    cout<<total;
    return 0;
    
}
