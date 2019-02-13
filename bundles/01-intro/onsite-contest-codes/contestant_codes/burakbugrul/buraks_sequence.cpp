#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    long long int cur;
    vector<long long int> B;

    scanf("%d", &N);

    B.resize(N);

    for( int i=0 ; i<N ; i++ )
        scanf("%d", &B[i]);
    
    cur = B[0];

    printf("%lld", cur);

    for( int i=1 ; i<N ; i++ ){

        long long int last = (B[i] * (i + 1)) - cur;
        cur += last;
        
        printf(" %lld", last);
    }

    puts("");
    return 0;
}
