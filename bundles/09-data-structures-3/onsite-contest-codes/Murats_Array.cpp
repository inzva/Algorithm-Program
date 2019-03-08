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

#define pii pair<int,int>
#define ll long long
#define N (int)(1e5+10)
#define mod 1000000007
#define mp make_pair
#define pb push_back
#define nd second
#define st first
#define inf mod
#define endl '\n'
#define rgt (lft|1)
#define lft (root<<1)
#define mid (beg+end)/2
#define bit(x,y) ((x>>y)&1)

int St[13][4*N];
int n,m,x,y,t,val,arr[N];

int que(int k,int root,int beg,int end,int x,int y){

	if(beg > y or end < x)
		return 0;
	
	if( x <= beg and end <= y)
		return St[k][root];

	return (que(k,lft,beg,mid,x,y) + que(k,rgt,mid+1,end,x,y))%mod;
}

int upd(int k,int root,int beg,int end,int x,int val){

	if(beg > x or end < x)
		return St[k][root];
	
	if(beg == end)
		return St[k][root] = (St[k][root] + val)%mod;

	return St[k][root] = (upd(k,lft,beg,mid,x,val) + upd(k,rgt,mid+1,end,x,val))%mod;
}

int main(){
	cin >> n >> m;

	for(int i=1 ; i<=n ; i++)
		cin >> arr[i];


	for(int i=n ; i>=1 ; i--){
		for(int k=m ; k>=2 ; k--){
			upd(k,1,1,n,arr[i],que(k-1,1,1,n,arr[i],n));
		}
		upd(1,1,1,n,arr[i],1);

	}

	cout << que(m,1,1,n,1,n) << endl;
}