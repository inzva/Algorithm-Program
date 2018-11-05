#include <iostream>

#define mod 1000000007

using namespace std;

long long exp(long long n, long long k){
    if(k == 0) return 1;
    if(k == 1) return n;
    
    long long temp = exp(n, k>>1) % mod;
    
    return ((k&1) == 1) ? (n * ( (temp * temp) % mod ) ) % mod : (temp * temp) % mod;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        long long sum = (exp(2LL, n)-1)%mod;
        
        printf("%lld\n", sum);
    }
}


