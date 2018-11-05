#include <bits/stdc++.h>
#define mod 1000000000

using namespace std;

long long vals[1005][1005];

void fill(){
    vals[0][0] = 1;
    vals[1][0] = 1;
    vals[1][1] = 1;
    
    for(int i=2;i<1001;i++){
        vals[i][0] = 1;
        for(int j=1;j<i;j++){
            vals[i][j] = (vals[i-1][j] + vals[i-1][j-1]) % mod;
        }
        vals[i][i] = 1;
    }
}

int main(){
    int t,n;
    scanf("%d",&t);
    
    fill();
    
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=n;i++){
            printf("%lld ", vals[n][i]);
        }
        printf("\n");
    }
    
    
    return 0;
}


