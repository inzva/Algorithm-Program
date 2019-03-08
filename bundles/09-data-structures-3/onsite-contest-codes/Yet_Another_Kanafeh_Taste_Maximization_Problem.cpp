// #include <algorithm>
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
#define bit(x,y) ((x/pw[y])%2)

ll tme = 1,i,x,mx,n,pw[555];
ll wh[155*N],A[155*N][2],sz[155*N];
ll suf[N];

ll que(int root,int i,long long x){

    if(i == -1){
        return wh[root];
    }

    if(sz[A[root][!bit(x,i)]])
        return que(A[root][!bit(x,i)],i-1,x);
    else
        return que(A[root][bit(x,i)],i-1,x);

}

void add(int root,int i,long long x){

    if(i == -1){
        sz[root]++;
        return;
    }

    if(A[root][bit(x,i)] == 0){
        A[root][bit(x,i)] = ++tme;

        if(i == 0){
            wh[tme] = x;
        }
    }

    add(A[root][bit(x,i)] , i-1 , x);
    
    sz[root]++;
}
void rem(int root,int i,long long x){

    if(i == -1){
        sz[root]--;
        return;
    }

    rem(A[root][bit(x,i)] , i-1 , x);
    
    sz[root]--;
}


ll arr[N];

int main(){
    cin >> n;

    for(int i=1 ; i<=n ; i++){
        cin >> arr[i];
        
    }
    
    pw[0] = 1;
    
    for(int i=1 ; i<=62 ; i++)
        pw[i] = pw[i-1] * 2;
    
    for(int i=n ; i>=1 ; i--){
        suf[i] = suf[i+1] ^ arr[i];
        
        add(1,43,suf[i]);
        
        mx = max(mx,suf[i]);
    }
    
    add(1,43,0);

    mx = que(1,43,0);
    
    
    ll pre = 0;
    
    for(int i=1 ; i<=n ; i++){
        rem(1,43,suf[i]);
        
        pre ^= arr[i];
        
        mx = max(que(1,43,pre) ^ pre , mx);
        
        mx = max(mx , pre);
        
    }


    cout << mx << endl;
}