#include <cstdio>
#include <cmath>
#include <queue>

using namespace std;

int N;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int> > min_heap;

int main() {
    
    scanf("%d", &N);
    
    for( int num, i=1 ; i <= N ; i++ ) {
        
        scanf("%d", &num);
        
        if( !max_heap.empty() && max_heap.top() > num ) { // Finding the corret half for new number 'num'
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        
        
        if( max_heap.size() - min_heap.size() == 2 ) { // Balancing the heaps in order to find the median in O(1) time copmlexity
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if( min_heap.size() - max_heap.size() == 2 ) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        
        if( i & 1 && max_heap.size() > min_heap.size() ) { // When there are odd number of numbers, the median is the top of the bigger heap
            printf("%d\n", max_heap.top());
        } else if( i & 1 && min_heap.size() > max_heap.size()) {
            printf("%d\n", min_heap.top());
        } else { // Otherwise, the median is average of tops of the heaps
            printf("%d\n", (max_heap.top() + min_heap.top()) >> 1);
        }
        
    }
    
    
    return 0;
}