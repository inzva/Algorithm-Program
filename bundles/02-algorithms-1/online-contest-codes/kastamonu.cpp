#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <iomanip>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

#define For(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define Rep(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define Ford(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define foreach(i,a) for(__typeof(a.begin()) i = a.begin() ; (i)!=a.end() ; (i)++ )
#define fi first
#define se second
#define dbg(x) cerr<<#x<<":"<<x<<endl;
#define dg(x) cerr<<#x<<":"<<x<<' ';
#define mp make_pair

using namespace std;

typedef pair<int,int> ii;
typedef long long Lint;

const int MAXN = 5e5+5;

typedef long double dbl;

int ar[MAXN];
int N;
int v[MAXN];
	
bool f(dbl k){
	
	dbl left = 1e27;
	bool ok = false ;
		
	Ford(i,N,1){
		
		if(v[i]>0){
			
			if(left<=ar[i]+v[i]*k && ok) 
				return true;
			
		}else{
			
			ok = true ; 
			left = min(left,ar[i]+v[i]*k);
			
		}

	} 

	return false;
	
}

int main(){

	cin >> N ; 
	
	For(i,1,N) scanf(" %d",ar+i) , scanf(" %d",v+i);
	
	dbl l = 0, r = 1e18;
	
	For(i,1,100){
	
		dbl m = (l+r)/2;
		
		if(f(m)) r = m ; 
		else l = m ; 
	
	}
	
	if(r==1e18) cout << -1 << endl , 0 ;
	else cout << setprecision(10) << fixed << r << endl;
	
	return 0;
}
