#include <cstdio>
#include <stack>

using namespace std;

int N, P, result;
stack<int> stacks[7];

int main() {
    
    scanf("%d%d", &N, &P);
    
    for( int s, f, i=0 ; i < N ; i++ ) {
        
        scanf("%d%d", &s, &f);
        
        while( stacks[s].size() && stacks[s].top() > f ) { // Releasing the fingers
            stacks[s].pop();
            result++;
        }
        
        if( stacks[s].empty() || (stacks[s].size() && stacks[s].top() != f ) ) { // Putting the finger
            result++;
            stacks[s].push(f);
        }
        
    }
    
    printf("%d\n", result);

    return 0;
}