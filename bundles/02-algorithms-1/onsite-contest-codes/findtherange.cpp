#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define orta ((bas+son)/2)
#define N 1000005
using namespace std;

int n, q, l[N], r[N], x, bas, son;

int main() {
    scanf("%d %d",&n ,&q);
    for(int i = 1; i <= n; i++)
        scanf("%d %d",&l[i] ,&r[i]);
    while(q--){
        scanf("%d",&x);
        bas = 1;
        son = n;
        while(bas < son){
            if(l[orta] > x)
                son = orta - 1;
            else if(r[orta] < x)
                bas = orta + 1;
            else
                break;
        }
        if(l[orta] <= x and r[orta] >= x)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}