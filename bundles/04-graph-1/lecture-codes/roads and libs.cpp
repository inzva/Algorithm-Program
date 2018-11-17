#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector <int> adj[N];
int mark[N];
void dfs(int k)
{
	mark[k]=1;
	for	(int i=0; i < (int)adj[k].size(); i++)	
		if(mark[adj[k][i]]==0)
			dfs(adj[k][i]);
}
void solve()
{
	memset(mark,0,sizeof(mark));
	int n,m,cl,cr;
	scanf("%d %d %d %d",&n,&m,&cl,&cr);
	for	(int i=0;i<=n;i++)
		adj[i].clear();
	for(int i=0; i<m;i++)
	{
		int o1,o2;
		scanf("%d %d",&o1,&o2);
		adj[o1].push_back(o2);
		adj[o2].push_back(o1);
	}
	int cc=0;
	for(int i=1;i<=n;i++)
		if(mark[i]==0)
		{
			dfs(i);
			cc++;
		}
	printf("%lld\n",min(n*1ll*cl , (cc*1ll*cl) + (n-cc)*1ll*cr));
}
int main()
{
	int ts;
	scanf("%d",&ts);
	while(ts--)
	{
		solve();
	}
}
