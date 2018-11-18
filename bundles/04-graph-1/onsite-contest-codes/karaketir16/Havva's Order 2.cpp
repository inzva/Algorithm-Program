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
vector<int> result;
struct Node
{
    bool visited=0;
    set<int> adj; 
};
void dfs_pre(vector<Node> &nodes, int r)
{
    if(nodes[r].visited) return;
    nodes[r].visited=true;
    result.pb(r);
    for(auto x: nodes[r].adj)
    {
        dfs_pre(nodes, x);
    }
}
void dfs_post(vector<Node> &nodes, int r)
{
    if(nodes[r].visited) return;
    nodes[r].visited=true;

    for(auto x: nodes[r].adj)
    {
        dfs_post(nodes, x);
    }
    result.pb(r);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<Node> nodes(n+1);
        for(int i=0;i<n-1;i++)
        {

            int x,y;
            scanf("%d %d", &x, &y);
            nodes[x].adj.insert(y);
            nodes[y].adj.insert(x);
        }
        nodes[1].visited=true;
        int a=0;
        for(auto x: nodes[1].adj)
        {
            //cout<<"test";
            if(a==0)
            {
                dfs_pre(nodes, x);
            }
            if(a==1)
            {
                result.pb(1);
                dfs_post(nodes, x);
            }
            a++;
        }
        for(auto x: result)
        {
            cout<<x<<' ';
        }
        cout<<'\n';
        vector<int> bb;
        result=bb;
    }

    return 0;
}