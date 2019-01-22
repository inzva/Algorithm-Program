#include <cstdio>
#include <cmath>

inline int calculate_interval( int last, int cur, int k ){

    if( last > cur )
        return 0;
    
    return ceil((cur - last - 2 * k - 1) / (double)(2 * k + 1));
}

int main(){

    int N, M, K, last, cur, result = 0;

    scanf("%d%d%d", &N, &M, &K);

    last = - K;

    for( int i=0 ; i<M ; i++ ){

        scanf("%d", &cur);
        
        result += calculate_interval(last, cur, K);

        last = cur;
    }

    result += calculate_interval(last, N + K + 1, K);

    printf("%d\n", result);
    return 0;
}
