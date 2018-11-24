#include <cmath>
#include <cstdio>
#include <utility>
#include <vector>
#include <iostream>
#include <climits>
#include <limits>
#include <algorithm>
#include <iostream>
#include <set>
#include <fstream>
#include <istream>
#include <ostream>
#include <queue>
#include <bitset>
#include <map>
#include <stack>
#include <ctype.h>

#define ll long long
#define maxn 500005

using namespace std;


int visited[maxn];
bool isReachable[maxn];

ll counter = 0;
vector<vector<int>> tree;

void dfs(int currentNode, int currentCount, int parentNode){
    // If the current count is smaller than two, we can always access that node.
    if(currentCount <= 2) isReachable[currentNode] = true;
    
    
    // Moving on the tree
    for (int t : tree[currentNode]) {
        if(visited[t] == 0){
            visited[t] = 1;
            dfs(t, currentCount+1, currentNode);
        }
    }
    
    // When we are returning from the leaf node. Check if we can reach that node.
    // If we can not reach, construct a road to its' parent.
    if(!isReachable[currentNode]){
        isReachable[parentNode] = true;
        for(int t : tree[parentNode]) isReachable[t] = true;
        counter++;
    }
    
    
    
}

int main() {
    int n,m,a,b;
    scanf("%d%d", &n, &m);
    
    tree.resize(maxn);
    for(int i=0;i<n-1;i++){
        scanf("%d %d", &a, &b);
        
        tree[a-1].push_back(b-1);
        tree[b-1].push_back(a-1);
    }
    
    visited[0] = 1;
    dfs(0, 0, 0);
    
    ll output = (ll)m*(ll)counter;
    printf("%lld\n", output);
    
    
    return 0;
}

