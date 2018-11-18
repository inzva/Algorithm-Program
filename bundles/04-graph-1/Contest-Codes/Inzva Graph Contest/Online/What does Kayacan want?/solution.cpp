#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <chrono>
#include <cassert>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node){
    for (int i : graph[node])
        if(!visited[i])
            visited[i] = true, dfs(i);
    
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    graph.resize(n);
    for(int x,y,i=0;i<m;i++){
        scanf("%d %d", &x, &y);
        
        graph[x-1].push_back(y-1);
        graph[y-1].push_back(x-1);
    }
    
    visited.resize(n+1, false); visited[0] = true;
    
    dfs(0);
    
    for(int i=0;i<n;i++){
        if(!visited[i]) {
            printf("Not Connected");
            return 0;
        }
    }
    
    printf("Connected");
    return 0;
}






