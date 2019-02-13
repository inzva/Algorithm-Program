#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    int N;
    long long int result = 1e15;
    vector<int> ar;

    scanf("%d", &N);

    ar.resize(N);

    for( int i=0 ; i<N ; i++ )
        scanf("%d", &ar[i]);
    
    for( int i=1 ; i < (1 << N); i++ ){ // Iterating all subsets

        long long int sum = 0;

        for( int j=0 ; j<N ; j++ ) // Iterating over elements of current subset
            if( (1 << j) & i )
                sum += ar[j];
        
        result = min(result, abs(sum));
    }

    printf("%lld\n", result);
    return 0;
}
