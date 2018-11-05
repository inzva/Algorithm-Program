#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<ll> divSum;

void findDivisorSum() {
    for(int i=1;i<divSum.size();i++)
        for(int j=i*2;j<divSum.size();j+=i)
            divSum[j] += i;
}

int main() {
    int a,b;
    
    scanf("%d %d", &a, &b);
    
    divSum.resize(b+1, 0);
    
    findDivisorSum();
    
    ll finalSum = 0;
    
    for(int i=a;i<=b;i++)
        finalSum += abs(i - divSum[i]);
    
    printf("%lld\n", finalSum);
    
    return 0;
    
}
