#include <cstdio>
#include <iostream>

using namespace std;

const int MAXN = 1e5 + 15;

int N, M, K;

int l[MAXN], r[MAXN], d[MAXN]; // Left, Right points of operations written on the paper and their increase amounts

long long int performs[MAXN]; // Perform amounts of operations written on the paper
long long int result[MAXN]; // Real result array

int main() {
    
    long long int cur = 0LL;
    
    scanf("%d%d%d", &N, &M, &K);
    
    for( int i=1 ; i <= M ; i++ ) {
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
    }
    
    for( int x, y, i=0 ; i < K ; i++ ) {
        
        scanf("%d%d", &x, &y);
        
        performs[x]++; // In order to add 1 to all elements that lies in range performs[x]...performs[y]
        performs[y + 1]--;
    }
    
    
    for( int i=1 ; i <= M ; i++ ) {
        
        cur += performs[i]; // Getting the value of the current indice 

        result[l[i]] += cur * d[i]; // In order to add (ur * d[i]) to all elements that lies in range result[l[i]]...result[r[i]]
        result[r[i] + 1] -= cur * d[i];
    }
    
    cur = 0LL;
    
    for( int i=1 ; i <= N ; i++ ) { // Obtaining the resulting array
        
        cur += result[i];
        
        printf("%lld ", cur);
    }
    
    return 0;
}