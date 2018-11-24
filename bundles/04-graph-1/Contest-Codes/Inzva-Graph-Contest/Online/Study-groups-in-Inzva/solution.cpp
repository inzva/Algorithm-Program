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

vector<pair<int,int>> moves = {{-1,-1}, {-1,0},{-1,1},{1,1},{1,0},{1,-1},{0,1},{0,-1} };
vector<vector<bool>> visited;
vector<string> matrix;


int findIslandSize(int a, int b, int n, int m){
    
    if(visited[a][b]) return -1;
    
    queue<pair<int, int>> q;
    q.push(make_pair(a,b));
    
    visited[a][b] = true;
    
    int size = 0;
    while(!q.empty()){
        pair<int,int> currLocation = q.front(); q.pop();
        
        for (auto &move : moves) {
            int x = currLocation.first + move.first, y = currLocation.second + move.second;
            if(x >= 0 && x < n && y >= 0 && y < m  && matrix[x][y] == '1' && !visited[x][y]){
                visited[x][y] = true;
                q.push(make_pair(x,y));
            }
        }
        
        size++;
        
    }
    
    return size;
    
}

int main(){
    int n,p,a,b;
    scanf("%d %d", &n, &p);
    
    vector<int> groups(n);
    for(auto &g : groups) scanf("%d", &g);
    
    
    scanf("%d%d\n",&a, &b);
    matrix.resize(a, string(b,0));
    for(auto &row : matrix) cin >> row;
    
    
    vector<pair<int,int>> oneLocs;
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
            if(matrix[i][j] == '1')
                oneLocs.emplace_back(i,j);
    
    
    visited.resize(a, vector<bool>(b,false));
    vector<int> islandSizes;
    

    for(auto one : oneLocs){
        int returnVal = findIslandSize(one.first, one.second, a, b);
        if(returnVal != -1) islandSizes.push_back(returnVal);
    }
    
    if(islandSizes.size() < n) {
        printf("-1");
        return 0; 
    }

    
    sort(islandSizes.begin(), islandSizes.end()); reverse(islandSizes.begin(), islandSizes.end());
    sort(groups.begin(), groups.end());reverse(groups.begin(), groups.end());
    
    for(int i=0;i<n;i++){
        if(groups[i] > islandSizes[i]){
            printf("-1");
            return 0;
        }
    }
    
    
    
    printf("%lld", (long long)p * (long long )n);
    
    
    return 0;
}






