#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 5000005
vector<int> adj[N];
vector<bool> visited(N,0);
void dfs(int a, int &count)
{
    if(visited[a]) return;
    visited[a]=1;
    count++;
    for(auto x:adj[a])
    {
        dfs(x, count);
    }
}
int main() {
    int n,m;
    int count=0;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        scanf("%d %d",&x ,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, count);
    if(count==n) cout<<"Connected\n";
    else cout<<"Not Connected\n";
    return 0;
}
