#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, q, x, y, a[N], yer[N];
pair < int , int > b[N], c[N];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    scanf("%d %d",&n ,&q);
    for(int i = 1; i <= n; i++)
        scanf("%d",&a[i]);


    for(int i = 1; i <= n; i++)
        b[i] = mp(a[i], i);
    sort(b + 1, b + n + 1);

    for(int i = 1; i <= n; i++)
        yer[b[i].nd] = i;

    while(q--){
        scanf("%d %d",&x ,&y);

        b[yer[x + 1]].st = y;

        pair < int , int > deg = b[yer[x + 1]];

        int ind = 0, f = 0;

        for(int i = 1; i <= n; i++){
            if(b[i] == deg)
                continue;
            if(f or b[i] < deg)
                c[++ind] = b[i];
            else{
                c[++ind] = deg;
                c[++ind] = b[i];
                f = 1;
            }
        }
        if(!f)
            c[++ind] = deg;

        for(int i = 1; i <= n; i++){
            b[i] = c[i];
            yer[b[i].nd] = i;
        }


        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, b[i].nd - i);
        printf("%d\n", ans);
    }
    return 0;
}