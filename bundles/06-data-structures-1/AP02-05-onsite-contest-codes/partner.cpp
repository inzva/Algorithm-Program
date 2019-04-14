#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

const int MAXN = 1e6+16;

int N;
int ar[MAXN];
int L[MAXN];
int R[MAXN];
int bit[MAXN];

long long int res;

unordered_map<int, int> cnt;

inline void add( int ind , int val ) { // Fenwick add function

    for( int i=ind ; i <= N ; i += i&-i )
        bit[i] += val;
}

inline int sum( int l, int r ) { // Fenwick range sum function

    int rev = 0;

    for( int i=r ; i ; i -= i&-i )
        rev += bit[i];
    
    for( int i=l-1 ; i ; i -= i&-i )
        rev -= bit[i];
    
    return rev;
}

int main(){

    scanf("%d", &N);

    for( int i=1 ; i<=N ; i++ )
        scanf("%d", ar+i);
    
    for( int i=1 ; i<=N ; i++ ){
        cnt[ar[i]]++;
        L[i] = cnt[ar[i]]; // L[i] is f(1, i, ar[i])
    }

    cnt.clear();

    // We are wnated to find number of (i, j) pairs that satisfies ->  L[i] > R[j] where i < j

    for( int i=N ; i ; i-- ){
        cnt[ar[i]]++;
        R[i] = cnt[ar[i]]; // R[i] is f(i, N, ar[i])
        add(R[i], 1); // We increased bit[R[i]] by one in order to use this for bigger L[i] values
    }

    for( int i=1 ; i<N ; i++ ){
        add(R[i], -1); // Deleting R[i] beacuse we are iterating through L array, we can't use R[i] anymore
        res += sum(1, L[i]-1); // Adding all smaller R[i]s to our result
    }
    
    printf("%lld\n", res);
    return 0;
}