#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define orta ((bas+son+1)/2)
#define N 1000005
using namespace std;

int n, a[N], b[N], bas = 1, son;

bool bul(int x){
    for(int i = 1; i <= n; i++)
        if(a[i] >= x)
            b[i] = 1;
        else
            b[i] = 0;
    for(int i = n/2 + 1; i > 1; i--){
        if(b[i] == b[i - 1])
            return b[i];
        if(b[n - i + 1] == b[n - i + 2])
            return b[n - i + 1];
    }
    return b[1];
}

int main() {
    scanf("%d",&n);
    n = n+n-1;
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    son = n;
    while(bas < son){
        if(bul(orta))
            bas = orta;
        else
            son = orta - 1;
    }
    printf("%d\n", orta);
    return 0;
}