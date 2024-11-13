---
title: Cycle Finding
tags:
    - Graph
    - Cycle
---

**Cycle**: A sequence of nodes that returns to the starting node while visiting each node at most once and contains at least two nodes. 

We can use dfs order in order to find the graph has a cycle or not.

If we find a back edge while traversing the graph then we can say that graph has a cycle. Because **back edge** connects the nodes at the top and bottom ends and causes a cycle.

The algorithm that we are going to use to find the cycle in the directed graph:

- Traverse the graph with dfs order.
- When you come to a node, color it gray and start visiting its neighbors.
- If one of the current node's neighbors is gray, then there is a cycle in the graph. Because a gray node is definitely an ancestor of the current node, and an edge to one of its ancestors is definitely a back edge.
- Once you're done visiting the neighbors, color the node black.

```cpp
bool dfs(int node){
    // The color array holds the color of each node.
    // 0 represents white, 1 represents gray, and 2 represents black.
    color[node] = 1;
    for(int i = 0; i < g[node].size(); i++){
        int child = g[node][i];
        if(color[child] == 1)
            return true;
        if(!color[child])
            if(dfs(child))
                return true;
    }
    color[node] = 2;
    return false;
}
```
