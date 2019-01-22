#include <bits/stdc++.h>
using namespace std;
#define N 100005
typedef long long int lint;
vector<lint> pre;
vector<lint> post;
void dfs_pre(int r, vector<set<int>> &adj, vector<bool> &visited)
{
    if(visited[r]) return;
    visited[r]= true;
    pre.push_back(r);
    for(auto x:adj[r]) dfs_pre(x, adj, visited);
}
void dfs_post(int r, vector<set<int>> &adj, vector<bool> &visited)
{
    if(visited[r]) return;
    visited[r]= true;
    for(auto x:adj[r]) dfs_post(x, adj, visited);
    post.push_back(r);
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        pre.clear();
        post.clear();

        vector<set<int>> adj(N);
        int n,r;
        cin>>n>>r;
        for(int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d %d", &x, &y);
            adj[x].insert(y);
            adj[y].insert(x);
        }
        {
            vector<bool> visited(N, 0);
            dfs_pre(r, adj, visited);
        }
        {
            vector<bool> visited(N, 0);
            dfs_post(r, adj, visited);
        }
        //for(int i=0;i<n;i++) cout<<pre[i]<<' ';
        //cout<<'\n';
        //for(int i=0;i<n;i++) cout<<post[i]<<' ';
        //cout<<'\n';
        for(int i=0;i<n;i++) printf("%lld ", pre[i]*post[i]);
        cout<<'\n';
        
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
