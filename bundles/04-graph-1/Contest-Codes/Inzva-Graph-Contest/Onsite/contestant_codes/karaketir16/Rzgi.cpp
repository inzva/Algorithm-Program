#include <bits/stdc++.h>
#define pb push_back
//#define fi first
//#define sc second
#define inf    1000000000000000LL
//#define MP make_pair
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define dbg(x) cerr<<#x<<":"<<x<<endl
#define N 100005
#define MOD 1000000007
#define orta ((a+b)/2)
#define fi first
#define sc second.first 
#define td second.second 
#define MP3(a,b,c) make_pair(a, make_pair(b,c))
using namespace std;
typedef long long int lint;

struct Node
{
    bool visited=0;
    double needed=-1;
    vector<pair<int ,pair<double, int>>> adj;// fi node, sc percent, td is_super
};
double dfs(vector<Node> &nodes, int r)
{
    if(nodes[r].needed!=-1) return nodes[r].needed;
    //if(nodes[r].visited) return visited ise hic gonderme
    nodes[r].visited=1;
    double maxx=0;
    for(auto x:nodes[r].adj)
    {
        int nd = x.fi;
        double percent= x.sc;
        int is_super= x.td;
        if(nodes[nd].visited) continue;
        double neded=dfs(nodes, nd);
        if(is_super) neded=sqrt(neded);
        neded=neded*((double)100/percent);
        maxx=max(maxx, neded);
    }
    return maxx;
    //return 0;
}
int main() {
    int n;
    cin>>n;
    vector<Node> nodes(n+1);
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        double x;
        int t;
        scanf("%d %d %lf %d",&a,&b,&x,&t);
        nodes[a].adj.pb(MP3(b,x,t));
        nodes[b].adj.pb(MP3(a,x,t));
    }
    for(int i=1;i<=n;i++)
    {
        double x;
        scanf("%lf", &x);
        nodes[i].needed=x;
    }
    int a;
    //cin>>a>>a>>a>>a;
    double d = 3.14159265358979;
    cout.precision(3);
    //cout << "Pi: " << fixed << d << endl;
    cout<<fixed<<dfs(nodes, 1);
    return 0;
}
