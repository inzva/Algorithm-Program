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

int bfs(vector<vector<int>> &graph, int a, int b){
    queue<pair<int,int>> q;
    q.push(make_pair(a, 0));
    
    vector<bool> visited(graph.size(), false);
    visited[a] = true;
    
    int dist = INT_MAX;
    while(!q.empty()){
        pair<int, int> cNode = q.front(); q.pop();
        
        if(cNode.first == b) dist = min(cNode.second, dist);
        
        for(auto node : graph[cNode.first]){
            if(!visited[node]){
                visited[node] = true;
                q.push(make_pair(node, cNode.second+1));
            }
        }
        
    }
    
    return dist;
}

int main(){
    int t,n,m,a,b;
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%d%d%d%d", &n, &m, &a, &b);
        vector<vector<int>> graph;
        graph.clear(); graph.resize((unsigned long)n + 5);
        for(int z,x,i=0;i<m;i++){
            scanf("%d%d",&z,&x);
            graph[z].push_back(x);
        }
        
        int dist = bfs(graph, a, b);
        if(dist == INT_MAX){
            printf("No Path!\n");
        }else {
            printf("%d\n", dist);
        }
        
        if(t != 0) printf("--\n");
    }
    
    
    return 0;
}







