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

struct Node
{
    bool visited=0;
    vector<int> child;
};
int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(a==b)
        {
            cout<<0<<'\n';
            continue;
        }
        vector<Node> nodes(n+1);
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d %d", &x,&y);
            nodes[x].child.pb(y);
        }
        queue<pair<int,int>> qu;//dist, node
        int dist=0;
        qu.push(MP(dist, a));
        //nodes[a].visited=1;
        bool found=0;
        while(!qu.empty())
        {
            pair<int, int> temp = qu.front();
            qu.pop();
            dist = temp.fi;
            int nd = temp.sc;
            if(nodes[nd].visited) continue;
            nodes[nd].visited=1;
            //cout<<"test: "<<nd<<endl;
            if(b==nd)
            {
                found=1;
                dist=dist;
                break;
            }
            for(auto x: nodes[nd].child)
            {
                qu.push(MP(dist+1, x));
            }
        }
        if(found) cout<<dist<<'\n';
        else cout<<"No Path!\n";
        if(t!=0)cout<<"--\n";
    }
    return 0;
}
