#include <iostream>

using namespace std;

#define mod 1000000007


int main() {
    int n,r;
    
    scanf("%d%d",&n,&r);
    
    int dest = n-r;
    
    long long output = 1;
    while(n > dest){
        output = (output * n) % mod;
        n--;
    }
    
    printf("%lld\n", output);
    
    return 0;
    
}
