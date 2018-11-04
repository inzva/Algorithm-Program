#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define orta ((bas+son)/2)
#define N 1000005
using namespace std;

int n, bas = 0, son = 1000000000, a[2][N];

bool dene(int x){

    vector < int > b[2];//X guc ile kaldiramadigimiz agirliklar.

    for(int i = 0; i < 2; i++)
        for(int j = 1; j <= n; j++)
            if(a[i][j] > x)
                b[i].pb(a[i][j]);
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < b[i].size(); j+=2)
            if(j + 1 >= b[i].size() or b[i][j] != b[i][j + 1])
                return 0;
    return 1;
}

int main() {
    scanf("%d",&n);
    for(int j = 0; j < 2; j++)
        for(int i = 1; i <= n; i++)
            scanf("%d",&a[j][i]);
    while(bas < son){
        if(dene(orta))
            son = orta;
        else
            bas = orta + 1;
    }
    printf("%d\n", orta);
    return 0;
}