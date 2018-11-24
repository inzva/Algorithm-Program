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


struct Node {
    int number, isSuper;
    double percent;
};
vector<vector<Node>> tree;
vector<double> need;
vector<bool> visited;


void dfs(int cNode, double percent, int isSuper, int parent){
    
    for(auto t : tree[cNode]){
        if(!visited[t.number]){
            visited[t.number] = true;
            dfs(t.number, t.percent, t.isSuper, cNode);
        }
    }
    
    if(cNode != 0) {
        if (isSuper == 1) {
            need[parent] = max(need[parent], (sqrt(need[cNode]) * 100.0) / percent);
        } else {
            need[parent] = max(need[parent], (need[cNode] * 100.0) / percent);
        }
    }
    
}


int main(){
    int n;
    scanf("%d", &n);
    tree.resize(n+1);
    need.resize(n+1);
    visited.resize(n+1, false);
    
    int a,b,d;
    double c;
    for(int i=0;i<n-1;i++){
        scanf("%d %d %lf %d", &a, &b, &c, &d);
        tree[a-1].push_back(Node{b-1,d, c});
    }
    
    for(int i=0;i<n;i++) scanf("%lf", &need[i]);
    
    visited[0] = true;
    dfs(0, 0, 0, -1);
    printf("%.6lf", need[0]);
    
    
    
    return 0;
}









