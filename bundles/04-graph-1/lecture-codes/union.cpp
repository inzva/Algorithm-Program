#include <bits/stdc++.h>

using namespace std;

const int N=100005;
int n,m,ata[N],ss,sil[N];
vector <pair <int,int> > edges;
vector <int> sy;
int cccount=0;
int parent(int k)
{
	if(ata[k]==k) return k;
	return ata[k]= parent(ata[k]);
}
void merge(int a,int b)
{
//	printf("%d %d\n",a,b);
	a = parent(a);
	b = parent(b);
	if(a==b) return ;
	cccount--;
	if(a>b) swap(a,b);
	ata[b] = a;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int o1,o2;
		scanf("%d %d",&o1,&o2);
		edges.push_back(make_pair(o1,o2));
	}
	cccount=n;
	for	(int i = 1 ; i <= n ; i++)
		ata[i]=i;

	int ss;
	scanf("%d",&ss); //silinme sayisi
	for(int i=0;i<ss;i++)
	{
		int o1;
		scanf("%d",&o1); // silinen yolun indisi
		sil[o1]=1;
		sy.push_back(o1);
	}

	reverse(sy.begin(),sy.end()); // silmek yerine ekliyoruz

	for(int i=0;i<m;i++)
		if(sil[i]==0)  // hic silinmeyenleri ekle
			merge(edges[i].first,edges[i].second);
	//		printf("sadfasfs\n");
	vector <int> ans;
	ans.clear();
	ans.push_back(cccount);
//	printf("%d\n",cccount);
	for	(int i=0; i < sy.size();i++)
	{
//		printf("%d\n",sy[i]);
		merge(edges[sy[i]].first,edges[sy[i]].second);	
//		printf("%d\n",cccount);
		ans.push_back(cccount);
	}
	reverse(ans.begin(),ans.end());
	for	(int i=0;i<ans.size();i++)
		printf("%d\n",ans[i]);
}
