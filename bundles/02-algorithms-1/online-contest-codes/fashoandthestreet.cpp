#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, l, a[N];
double ans;

int main() {
    scanf("%d %d",&n ,&l);
    for(int i = 1; i <= n; i++)
        scanf("%d",a + i);
    sort(a + 1, a + n + 1);
    for(int i = 1; i < n; i++)
        ans = max(ans, (a[i + 1] - a[i])/2.0);
    ans = max(ans, 1.0*a[1]);
    ans = max(ans, 1.0*l - a[n]);
    printf("%.6lf\n", ans);
    return 0;
}