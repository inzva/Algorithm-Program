---
title: Depth First Search
tags:
    - Graph
    - Depth First Search
    - DFS
---

Depth First Search (DFS) is an algorithm for traversing or searching tree. (For example, you can check if graph is connected or not via DFS) [2]

<figure markdown="span">
![Depth First Search](img/dfs.jpg)
<figcaption>Example of DFS traversal</figcaption>
</figure>

## Method

The DFS algorithm is a recursive algorithm that uses the idea of backtracking. It involves exhaustive searches of all the nodes by going ahead, if possible, else by backtracking.

Here, the word backtrack means that when you are moving forward and there are no more nodes along the current path, you move backwards on the same path to find nodes to traverse. All the nodes will be visited on the current path till all the unvisited nodes have been traversed after which the next path will be selected. [3]

```cpp
vector<vector<int» adj; // graph represented as an adjacency list
int n; // number of vertices
vector<bool> visited;
void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) dfs(u);
    }
}
```

This recursive nature of DFS can be implemented using stacks. The basic idea is as follows: Pick a starting node and push all its adjacent nodes into a stack. Pop a node from stack to select the next node to visit and push all its adjacent nodes into a stack. Repeat this process until the stack is empty. However, ensure that the nodes that are visited are marked. This will prevent you from visiting the same node more than once. If you do not mark the nodes that are visited and you visit the same node more than once, you may end up in an infinite loop. [3]

```cpp
DFS-iterative(G, s): //Where G is graph and s is source vertex let S be stack
S.push(s) //Inserting s in stack
mark s as visited.
while ( S is not empty):
    //Pop a vertex from stack to visit next v = S.top( )
    S.pop( )
    //Push all the neighbours of v in stack that are not visited
    for all neighbours w of v in Graph G:
        if w is not visited :
            S.push(w)
            mark w as visited
```

Example Question: Given an undirected graph, find out whether the graph is strongly connected or not? An undirected graph is strongly connected if there is a path between any two pair of vertices.


```cpp
#include <bits/stdc++.h>
using namespace std;

cont int MaxN=100005; // Max number of nodes

vector <int> adj[MaxN];
bool mark[MaxN];

void dfs(int k) {
    mark[k]=1; // visited
    for(auto j : adj[k]) // iterate over adjacent nodes
        if(mark[j]==false) // check if it is visited or not
            dfs(j); // do these operation for that node
}

int main() {
    cin » n » m; // number of nodes , number of edges
    for (int i=0 ; i < m; i++){
        cin » a » b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1);

    bool connected=1;
    for(int i=1 ; i <= n ;i++)
        if(mark[i]==0) {
            connected=0;
            break;
        }

    if(connected)
        cout « "Graph is connected" « endl;
    else
        cout « "Graph is not connected" « endl;

    return 0;
}
```

## Complexity

The time complexity of DFS is \(O(V+E)\) when implemented using an adjacency list ( with Adjacency Matrices it is \(O(V^2)\)), where \(V\) is the number of nodes and \(E\) is the number of edges. [4]
