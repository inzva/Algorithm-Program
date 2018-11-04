#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define orta ((bas+son)/2)
#define N 100005
using namespace std;

int n, a[N], b[N];
long long ans;

void sort(int bas, int son){
    if(bas == son)
        return;
    sort(bas, orta);
    sort(orta + 1, son);
    int i = bas, j = orta + 1, ind = 0;
    while(i <= orta and j <= son)
        if(a[i] <= a[j]){
            b[++ind] = a[i++];
            ans += j - orta - 1;
        }
        else
            b[++ind] = a[j++];
    while(i <= orta){
        b[++ind] = a[i++];
        ans += j - orta - 1;
    }
    while(j <= orta)
        b[++ind] = a[j++];
    for(int i = 1; i <= ind; i++)
        a[bas + i - 1] = b[i];
}

int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    sort(1, n);
    printf("%lld\n", ans);
    return 0;
}