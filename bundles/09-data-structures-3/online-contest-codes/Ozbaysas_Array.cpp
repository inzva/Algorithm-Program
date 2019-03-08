#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;
 
#define dbg(x) cerr << (#x) << " --> " << (x) << endl
#define lli long long int
#define pii pair< pair<int,int> ,int>
#define mod 1000000007
#define N (int)(200001)
#define mp make_pair
#define pb push_back
#define nd second
#define st first
#define endl '\n'
#define inf mod
#define sag (sol|1)
#define sol (root<<1)
#define ort ((bas+son)>>1)

vector< pii > q;
int g[N],arr[N];
int i,j,k,n,m,x,y,z;
int lx,ly,ans[N];
int t,S[N*10];

bool cmp(pii x,pii y){
	if(g[x.st.st] != g[y.st.st])
		return x.st.st < y.st.st;
	return x.st.nd < y.st.nd;
}

int f(int x,int y){
	int i;
	for(i=lx-1 ; i>=x ; i--){
		lx--;

		if((++S[arr[i]]) == 1)
			t ++;
	}
	
	for(i=ly+1 ; i<=y ; i++){
		ly++;
		if((++S[arr[i]]) == 1)
			t++;
	}

	for(i=ly ; i>y ; i--){
		ly--;
		if((--S[arr[i]]) == 0)
			t--;
	}
	for(i=lx ; i<x ; i++){
		lx++;
		if((--S[arr[i]]) == 0)
			t--;
	}
	return t;
}
int main(){

	//freopen(".gir","r",stdin);
	//freopen(".cik","w",stdout);

	cin >> n >> m;

	int kokn = sqrt(n);

	for(i=1 ; i<=n ; i++)
		g[i] = (i-1)/kokn+1;

	for(i=1 ; i<=n ; i++)
		scanf("%d",arr+i);

	for(i=1 ; i<=m ; i++){
		scanf("%d %d",&x,&y);
		q.pb(mp(mp(x,y),i));
	}

	sort(q.begin(),q.end(),cmp);

	for(i=0 ; i<m ; i++){
		ans[q[i].nd] = f(q[i].st.st,q[i].st.nd);
	}

	for(i=1 ; i<=m ; i++)
		printf("%d\n",ans[i]);
}
