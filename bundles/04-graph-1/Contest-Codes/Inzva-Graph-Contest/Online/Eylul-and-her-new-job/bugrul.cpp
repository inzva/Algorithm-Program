#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

// The first element in the pair represents the time taken
// The second element represents the index number.
typedef pair<long long int, long long int> llp;

const int MAXN = 2e6+26;

int N, M;

long long int ar[MAXN];

priority_queue<llp, vector<llp>, greater<llp>> pq;

int main(){
    
    scanf("%d%d", &N, &M);
    
    // Reading the input and pushing the index number to min heap.
    for(int i=1 ; i<=N ; i++ ){
        scanf("%lld", ar + i);
        pq.push(llp(0, i));
    }
    
    long long int tmp;
    
    for( int i=0 ; i<M ; i++ ){
        
        scanf("%lld", &tmp);
        
        // Poping the accessible cashier
        llp nx = pq.top();
        pq.pop();
        
        // Assigning accessible cashier to the new costumer.
        pq.push(llp(nx.first + tmp * ar[nx.second], nx.second));
    }
    
    // Pop until the last element since we want to have the maximum taken time.
    while( pq.size() != 1 )
        pq.pop();
    
    printf("%lld\n", pq.top().first);
    return 0;
}

