#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define vvll vector<vector<ll>>
#define mod 1000000007
vvll matrixMul(vvll a, vvll b){
    vvll c(2,vector<ll>(2,0));
    
    c[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % mod;
    c[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    c[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    c[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    
    return c;
}

vvll fastMatrixPow(ll n){
    if(n == 1){
        vvll temp(2,vector<ll>(2,0));
        temp[0][0] = 1, temp[0][1] = 1, temp[1][0] = 1, temp[1][1] = 0;
        
        return temp;
    }
    
    vvll returnMat = fastMatrixPow(n>>1);
    
    if(n%2 == 0){
        return matrixMul(returnMat, returnMat);
    }else {
        vvll temp(2,vector<ll>(2,0));
        temp[0][0] = 1, temp[0][1] = 1, temp[1][0] = 1, temp[1][1] = 0;
        
        return matrixMul(temp, matrixMul(returnMat, returnMat));
    }
}



int main() {
    ll n,a,b;
    
    scanf("%lld %lld %lld",&n,&a,&b);
    
    vvll matrixPow = fastMatrixPow(n);
    
    a %= mod, b %= mod;
    
    ll output = (matrixPow[1][0] * b +  matrixPow[1][1] * a) % mod;
    
    printf("%lld\n", output);
    
    return 0;
}

