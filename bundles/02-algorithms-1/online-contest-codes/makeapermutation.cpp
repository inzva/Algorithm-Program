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
        scanf("%d",a + i);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        ans += abs(a[i] - i);
    printf("%lld\n", ans);
    return 0;
}
