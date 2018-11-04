#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, a[N];
long long ans;

int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for(int i = 1; i <= n; i++){
        bool f = 0;
        for(int j = 1; j < n - i + 1; j++)
            if(a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
                f = 1;
                ans++;
            }
        if(!f)
            break;
    }
    printf("%lld\n", ans);
    return 0;
}