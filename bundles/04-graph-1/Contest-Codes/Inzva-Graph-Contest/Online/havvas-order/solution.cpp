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

vector<vector<int>> tree;
vector<bool> visited;
vector<int> pre;
vector<int> post;

void preOrder(int node){
    
    pre.push_back(node+1);
    for (int i : tree[node])
        if(!visited[i])
            visited[i] = true, preOrder(i);
    
}

void postOrder(int node){
    for (int i : tree[node])
        if(!visited[i])
            visited[i] = true, postOrder(i);
    
    post.push_back(node+1);
    
}

int main(){
    int t,n,z,x, r;
    scanf("%d", &t);
    
    long long output;
    while(t--){
        tree.clear();
        pre.clear();
        post.clear();
        
        scanf("%d %d", &n, &r);
        
        tree.resize(n+1);
        
        for(int i=0;i<n-1;i++){
            scanf("%d %d", &z, &x);
            tree[z-1].push_back(x-1);
            tree[x-1].push_back(z-1);
        }
        
        for(int i=0;i<n;i++)
            sort(tree[i].begin(), tree[i].end());
        
        
        visited.clear(); visited.resize(n+1, false); visited[r-1] = true;
        preOrder(r-1);
        
        visited.clear(); visited.resize(n+1, false); visited[r-1] = true;
        postOrder(r-1);
        
        
        for(int i=0;i < pre.size();i++){
            output = (long long)pre[i] * (long long)post[i];
            printf("%lld ", output);
        }
        printf("\n");
    }
    
    return 0;
}






