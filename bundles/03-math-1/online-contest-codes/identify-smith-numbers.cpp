#include <bits/stdc++.h>

using namespace std;

long long sumVal(long long n){
    long long g = 0;
    
    while(n > 0){
        g += n%10;
        n/=10;
    }
    
    return g;
}

bool isPrime(long long z){
    if(z == 0 || z == 1) return false;
    
    for(long long i=2;i*i<=z;i++){
        if(z%i == 0) return false;
    }
    
    return true;
}

long long howMany(long long z, long long a) {
    long long c = 0;
    
    while(z%a == 0){
        c++;
        z /= a;
    }
    
    return c;
    
}

int solve(int n) {
    long long nSum = sumVal(n);
    long long primeSum = 0;
    
    for(int i=2;i*i<n;i++){
        if(n%i == 0){
            if(isPrime(i)) primeSum += (howMany(n, i) * sumVal(i));
            if(isPrime(n/i)) primeSum += (howMany(n, n/i) * sumVal(n/i));
        }
    }
    
    return primeSum == nSum ? 1 : 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    int result = solve(n);
    
    fout << result << "\n";
    
    fout.close();
    
    return 0;
}
