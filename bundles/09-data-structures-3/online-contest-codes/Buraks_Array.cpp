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
#define sag (sol|1)
#define sol (root<<1)
#define ort (bas+son)/2
#define bit(x,y) ((x>>y)&1)

int tme = 1,i,x,mx,n;
int wh[40*N],A[40*N][2];

int que(int root,int i,int x){

	if(i == -1){
		return wh[root];
	}

	if(A[root][!bit(x,i)])
		return que(A[root][!bit(x,i)],i-1,x);
	else
		return que(A[root][bit(x,i)],i-1,x);

}

void add(int root,int i,int x){

	if(i == -1)
		return;

	if(A[root][bit(x,i)] == 0){
		A[root][bit(x,i)] = ++tme;

		if(i == 0){
			wh[tme] = x;
		}
	}

	add(A[root][bit(x,i)] , i-1 , x);
}

int main(){
	cin >> n;

	for(int i=1 ; i<=n ; i++){
		cin >> x;

		mx = max(que(1,31,x) ^ x , mx);

		add(1,31,x);
	}

	cout << mx << endl;
}