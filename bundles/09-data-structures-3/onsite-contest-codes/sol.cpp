#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define N 100005
#define Siz 405
#define LL long long
#define oo (1<<30)
using namespace std;
vector<int> G[N];
struct ask{ int num,l,r,k;}Q[N];
int n,m,cnt,ans[N],lt[N],rt[N],a[N],b[N],S[N],c[N];
bool cmp(ask p,ask q){ return p.l/Siz<q.l/Siz||(p.l/Siz==q.l/Siz&&p.r<q.r);}
void dfs(int t,int fa)
{
    int i; lt[t]=++cnt;
    for(i=0;i<G[t].size();i++)
        if(G[t][i]!=fa)
            dfs(G[t][i],t);
    rt[t]=cnt;
}
int main()
{
    int i,l,r;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<n;i++){
        scanf("%d %d",&l,&r);
        G[l].push_back(r);
        G[r].push_back(l);
      }
    dfs(1,0);
    for(i=1;i<=n;i++) a[lt[i]]=b[i];
    for(i=1;i<=m;i++){
        scanf("%d %d",&Q[i].l,&Q[i].k);
        Q[i].r=rt[Q[i].l];
        Q[i].l=lt[Q[i].l];
        Q[i].num=i;
      }
    sort(Q+1,Q+m+1,cmp);
    l=r=0;
    for(i=1;i<=m;i++){
        while(r+1<=Q[i].r) S[++c[a[++r]]]++;
        while(l-1>=Q[i].l) S[++c[a[--l]]]++;
        while(l<Q[i].l) S[c[a[l++]]--]--;
        while(r>Q[i].r) S[c[a[r--]]--]--;
        ans[Q[i].num]=S[Q[i].k];
      }
    for(i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}