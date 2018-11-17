#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, m, ans;
char s[N], t[N];

int main() {
    scanf("%s %s",t + 1, s + 1);
    n = strlen(t + 1);
    m = strlen(s + 1);
    for(int i = 1; i <= n; i++){
        int ekle = 1;
        for(int j = 1; j <= m; j++)
            if(t[i + j - 1] != s[j]){
                ekle = 0;
                break;
            }
        ans += ekle;
    }
    printf("%d\n",ans);
    return 0;
}