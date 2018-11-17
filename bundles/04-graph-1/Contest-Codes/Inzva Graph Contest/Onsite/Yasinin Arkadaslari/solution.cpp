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


#define N (int)(1e5+10)

int root[N];

int unionfind(int x){
    if(root[x] == x)
        return x;
    return root[x] = unionfind(root[x]);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i=1 ; i<=n ; i++)
        root[i] = i;
    
    for(int q,x,y,i=1 ; i<=m ; i++){
        scanf("%d%d%d", &q, &x, &y);
        
        if(q == 1){
            x = unionfind(x);
            y = unionfind(y);
            root[x] = y;
        }else{
            if(unionfind(x) == unionfind(y)) {
                printf("Connect\n");
            }else {
                printf("Not Connect\n");
            }
        }
    }
}
