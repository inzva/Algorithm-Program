#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, m;
long long ans;
pair < int , int > a[N];

int main() {
    scanf("%d %d",&n ,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d %d",&a[i].st ,&a[i].nd);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        if(a[i].nd <= m){
            m -= a[i].nd;
            ans += 1ll * a[i].nd * a[i].st;
        }else{
            ans += 1ll * a[i].st * m;
            break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}