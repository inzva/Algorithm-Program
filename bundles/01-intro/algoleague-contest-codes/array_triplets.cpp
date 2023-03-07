#include "bits/stdc++.h"

using namespace std;
long long N, A[20], ans;

void dfs(int i=0, long long S1=0, long long S2=0, long long S3=0, int C1=0, int C2=0, int C3=0){
    if (i == N){
        if (S1 == S2 and S2 == S3 and C1 and C2 and C3)
            ans++;
        return;
    }

    dfs(i + 1, S1+A[i], S2, S3, C1+1, C2, C3);
    dfs(i + 1, S1, S2+A[i], S3, C1, C2+1, C3);
    dfs(i + 1, S1, S2, S3+A[i], C1, C2, C3+1);
}


int main(int argc, char const *argv[]){
    scanf("%lld", &N);
    
    for (int i=0; i < N; i++)
        scanf("%lld", A + i);
    
    dfs();
    printf("%lld\n", ans);

    return 0;
}



