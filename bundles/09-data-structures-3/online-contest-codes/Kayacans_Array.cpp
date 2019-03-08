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

ll St[6*N],L[6*N];
int n,m,x,y,t,val;

void push(int root,int beg,int end){

	if(L[root]){
		St[lft] = mid-beg+1-St[lft];
		St[rgt] = end-mid-St[rgt];
		L[lft] ^= 1;
		L[rgt] ^= 1;
		L[root] = 0;
	}
}

ll que(int root,int beg,int end,int x){

	// cout << beg << ' ' << end << endl;

	if(end < x)
		return 0;

	push(root,beg,end);

	if(beg >= x){
		// if(beg == end)
			// cout << "#" << St[root] << endl;
		if(St[root] == end-beg+1)
			return 0;
		if(beg == end)
			return beg;
	}

	int t = que(lft,beg,mid,x);

	if(t)
		return t;

	return que(rgt,mid+1,end,x);

}

ll upd(int root,int beg,int end,int x,int y){

	if(beg > y or end < x)
		return St[root];
	
	if( x <= beg and end <= y){
		L[root] ^= 1;
		return St[root] = (end-beg+1) - St[root];
	}

	push(root,beg,end);

	return St[root] = upd(lft,beg,mid,x,y) + upd(rgt,mid+1,end,x,y);
}

void init(int root,int beg,int end){

	if(beg == end){
		St[root] = (beg <= n);
		return;
	}

	init(lft,beg,mid);
	init(rgt,mid+1,end);

	St[root] = St[lft] + St[rgt];
	return;
}

int main(){
	cin >> n >> m;

	init(1,1,n+1);

	for(int i=1 ; i<=m; i++){
		cin >> t >> x;

		if(t == 1){
			cin >> y;
			upd(1,1,n+1,x,y);
		}

		else{
			cout << que(1,1,n+1,x) << endl;
		}
	}
}