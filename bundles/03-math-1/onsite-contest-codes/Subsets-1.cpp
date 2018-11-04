#include <iostream>
#include <vector>
using namespace std;

#define mod 1000000007

int main() {
    int n;
    scanf("%d", &n);
    
    vector<int> vec(n);
    for(int i=0;i<n;i++) scanf("%d", &vec[i]);
    
    long long sumVal = 0;
    for(int i=0;i<n;i++) sumVal = (sumVal + vec[i]) % mod;
    
    long long twoPow = 1;
    for(int i=0;i<n-1;i++) twoPow = (twoPow * 2) % mod;
    
    long long ans = (twoPow * sumVal) % mod;
    
    printf("%lld", ans);
    
    return 0;
    
    
    
}
