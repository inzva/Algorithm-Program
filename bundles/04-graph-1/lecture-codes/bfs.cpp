#include <bits/stdc++.h>

using namespace std;

const int N=100005;
vector <int> adj[N];

int mark[N],gy[N];
int main()
{
	int n,m,bas,son;
	scanf("%d %d",&n,&m);
	for	(int i=0;i<m;i++)
	{
		int o1,o2;
		scanf("%d %d",&o1,&o2);
		adj[o1].push_back(o2);
	}
	scanf("%d %d",&bas,&son);
	
	queue <int> q;
	q.push(bas);
	mark[bas]=1;
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();
		if(tmp==son) break;
		for(int i=0;i < (int) adj[tmp].size();i++)
			if(mark[adj[tmp][i]]==0)
			{
				mark[adj[tmp][i]]=1;
				gy[adj[tmp][i]]=tmp;
				q.push(adj[tmp][i]);
			}
	}	
	vector <int> ans;
	
	ans.push_back(son);
	while(son!=bas)
	{
		son=gy[son];
		ans.push_back(son);
	}
	reverse(ans.begin(),ans.end());
	printf("%d\n",(int)ans.size()-1);
	for(int i=0;i<(int)ans.size();i++)
		printf("%d ",ans[i]);
}













