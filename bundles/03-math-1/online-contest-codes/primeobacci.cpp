#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

bool isPrime(int n){
    for(int i=2;i*i < n;i++){
        if(n%i == 0) return false;
    }
    
    return true;
}


int main() {
    int t,n;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);
        
        vvll matrixPow = fastMatrixPow(n-1);
        int output = (matrixPow[1][0]  +  matrixPow[1][1] ) % mod;
        
        
        if(isPrime(output))
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
        
    }
    return 0;
}


