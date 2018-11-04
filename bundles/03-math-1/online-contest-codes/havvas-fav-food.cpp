#include <iostream>
#include <vector>
#include <algorithm>

#define mod 1000000007
#define ll long long

const int maxn = 10000005;

bool isPrime[maxn];
bool isCube[maxn];
bool isFibo[maxn];

using namespace std;

void fibo() {
    int a = 1, b = 1, temp;
    while(b < maxn){
        isFibo[b] = true;
        temp = b;
        b = a + b;
        a = temp;
    }
}

void sieve(){
    isPrime[0] = false, isPrime[1] = false;
    
    for(int i=2; i*i<maxn; i++)
        if(isPrime[i])
            for(int j=i<<1; j<maxn; j+=i)
                isPrime[j] = false;
}

void cube() {
    for(int i=1;i*i*i<maxn; i++)
        isCube[i*i*i] = true;
}


int main(){
    for(int i=0;i<maxn;i++) isPrime[i] = true, isCube[i] = false;
    
    sieve();
    cube();
    fibo();
    
    int n, t, q ,z;
    scanf("%d %d", &n, &t);
    
    vector<int> input(n,0);
    for(auto &i : input) cin >> i; // scanf("%d", &i);
    
    
    while (t--) {
        scanf("%d %d", &q, &z);
        
        if(q == 1)
            cout << (isFibo[ input[z-1] ] ? "Fibonacci\n" : "Not Fibonacci\n") ;
        // printf(isFibo[ input[z-1] ] ? "Fibonacci\n" : "Not Fibonacci\n");
        else if(q == 2)
            cout << (isPrime[ input[z-1] ] ? "Prime\n" : "Not Prime\n") ;
        // printf(isPrime[ input[z-1] ] ? "Prime\n" : "Not Prime\n");
        else
            cout << (isCube[ input[z-1] ] ? "Cube\n" : "Not Cube\n") ;
        // printf(isCube[ input[z-1] ] ? "Cube\n" : "Not Cube\n");
        
    }
    
    
    
}



