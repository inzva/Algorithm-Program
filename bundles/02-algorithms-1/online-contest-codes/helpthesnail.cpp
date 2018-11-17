#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define N 1000005
using namespace std;

int n, x, a;

int main() {
    scanf("%d %d %d",&n ,&x ,&a);
    n--;
    x -= a;
    double kac = (double)x/n;
    printf("%d\n", (int)(a - kac));
    return 0;
}