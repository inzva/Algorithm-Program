#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <stack>
#include <bitset>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>

using namespace std;

vector<vector<int>> tree;

vector<bool> visited;

vector<int> leftVector, rightVector;

void findLeft(int c){
    
    leftVector.push_back(c+1);
    for (int node : tree[c])
        if(!visited[node])
            visited[node] = true, findLeft(node);
    
}

void findRight(int c){
    
    for (int node : tree[c])
        if(!visited[node])
            visited[node] = true, findRight(node);
    
    rightVector.push_back(c+1);
}

int main(){
    int t, n;
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);

        tree.clear(); tree.resize((unsigned long)n+1);
        visited.clear(); visited.resize((unsigned long)n+1, false);
        
        for(int z,b,i=0;i<n-1;i++){
            scanf("%d%d",&z,&b);
            tree[z-1].push_back(b-1);
            tree[b-1].push_back(z-1);
        }
        
        for(auto &c : tree)
            sort(c.begin(), c.end());
        
        visited[0] = true,visited[tree[0][0]] = true,visited[tree[0][1]] = true;
        findLeft(tree[0][0]); findRight(tree[0][1]);
        
        for(auto e : leftVector)
            printf("%d ", e);
        
        printf("1 ");
        
        for(auto e : rightVector)
            printf("%d ", e);
        
        printf("\n");
        
        leftVector.clear(), rightVector.clear();
        
    }
    
    
    return 0;
}








