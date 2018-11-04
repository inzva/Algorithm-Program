#include <bits/stdc++.h>
#define orta ((bas+son)/2)
#define N 100005
using namespace std;

int n, m, b, bas, son, a[N];

int main() {
    scanf("%d %d",&n ,&m);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    for(int i = 1; i <= m; i++){
        scanf("%d",&b);
        bas = 1, son = n;
        while(bas < son){
            if(a[orta] < b)
                bas = orta + 1;
            else
                son = orta;
        }
        if(a[orta] != b or a[orta + 1] == b)
            puts("-1");
        else
            printf("%d\n", orta);
    }
    return 0;
}