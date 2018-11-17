#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n, ans = 1, a[N];

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for(int i = 1; i <= n; i++)
        if(a[i] == 1){
            ans = -1;
            break;
        }
    printf("%d\n", ans);
    return 0;
}