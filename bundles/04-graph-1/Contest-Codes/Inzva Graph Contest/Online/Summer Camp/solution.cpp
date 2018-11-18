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
    int x,y,length;
    Node(int a, int b, int c){
        x = a, y = b, length = c;
    }
};

int bfs(int x, int y, int c, int v){
    
    bool visited[10][10];
    for (auto &i : visited) for (bool &j : i) j = false;
    visited[x][y] = true;
    
    queue<Node> q;
    q.push(Node(x, y, 0));
    
    vector<pair<int, int>> moves = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
    
    while(!q.empty()){
        Node cNode = q.front(); q.pop();
        
        if(cNode.x == c && cNode.y == v) return cNode.length;
        
        for(auto move : moves) {
            int xx = cNode.x + move.first , yy = cNode.y + move.second;
            
            if(xx >= 0 && xx < 8 && yy >= 0 && yy < 8){
                if(!visited[xx][yy]){
                    visited[xx][yy] = true;
                    q.push(Node(xx, yy, cNode.length+1));
                }
            }
        }
        
    }
    
    return 0;
    
}

int main(){
    
    int t;
    scanf("%d", &t);
    
    string a,b;
    while(t--){
        cin >> a >> b;
        int xOne = a[0]-'a', yOne = a[1]-'1';
        int xTwo = b[0]-'a', yTwo = b[1]-'1';
        
        cout<<"To get from "<< a <<" to "<< b <<" takes "<< bfs(xOne, yOne, xTwo, yTwo) <<" knight moves."<<endl;
    }
    
    
    return 0;
}








