#include <cstdio>

inline bool is_prime( int number ){

    if( !(number & 1) )
        return false;
    
    for( int i=3 ; i*i <= number ; i+=2 )
        if( number % i == 0 )
            return false;
    
    return true;
}

int main(){

    int N;

    scanf("%d", &N);

    for( int number, i=0 ; i<N ; i++ ){
        scanf("%d", &number);
        printf("%s\n", is_prime(number) ? "Prime" : "Not Prime");
    }

    return 0;
}
