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

struct Node {
    int xMany, yMany, currentx, currenty;
}node;

void findDist(vector<vector<int>>  &nodeType,vector<double> &manhattanDist, int n){
    vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
    
    queue<Node> q;
    node.currentx = 0, node.currenty = 0, node.xMany = 0, node.yMany = 0;
    q.push(node);
    
    visited[0][0] = true;
    
    vector<pair<int ,int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    while(!q.empty()) {
        Node curNode = q.front();
        q.pop();
        
        for (auto move : moves) {
            int x = curNode.currentx + move.first, y = curNode.currenty + move.second;
            
            if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && nodeType[x][y] != 1) {
                visited[x][y] = true;
                
                node.xMany = curNode.xMany + abs(move.first), node.yMany = curNode.yMany + abs(move.second);
                node.currentx = x, node.currenty = y;
                q.push(node);
                
                if (nodeType[x][y] == 2)
                manhattanDist.push_back(node.xMany + node.yMany);
            }
        }
        
        
        
        
    }
    
}


int main(){
    int n, g, h, t;
    scanf("%d %d %d %d", &n, &g, &h, &t);
    vector<vector<int>> nodeType(n+1, vector<int>(n+1, 0));
    
    for(int x,y,i=0;i<g;i++){
        scanf("%d %d\n", &x, &y);
        
        nodeType[x][y] = 1;
    }
    
    for(int x,y,i=0;i<h;i++){
        scanf("%d %d\n", &x, &y);
        
        nodeType[x][y] = 2;
    }
    
    vector<double> manhattanDist;
    
    findDist(nodeType, manhattanDist, n);
    
    int a;
    long loc;
    for(int i=0;i<t;i++){
        scanf("%d", &a);
        loc = upper_bound(manhattanDist.begin(), manhattanDist.end(), a) - manhattanDist.begin();
        printf("%ld\n", loc);
    }
    
    return 0;
}







