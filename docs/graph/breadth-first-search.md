---
title: Breadth First Search
tags:
    - Graph
    - Breadth First Search
    - BFS
---

Breadth First Search (BFS) is an algorithm for traversing or searching tree. (For example, you can find the shortest path from one node to another in an unweighted graph.)

<figure markdown="span">
![Breadth First Search Traversal](img/bfs.jpg)
<figcaption>An example breadth first search traversal</figcaption>
</figure>

## Method

BFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph layerwise thus exploring the neighbour nodes (nodes which are directly connected to source node). You must then move towards the next-level neighbour nodes. [1]

• As the name BFS suggests, you are required to traverse the graph breadthwise as follows:
• First move horizontally and visit all the nodes of the current layer
• Add to the queue neighbour nodes of current layer.
• Move to the next layer, which are in the queue

Example question: Given a unweighted graph, a source and a destination, we need to find shortest path from source to destination in the graph in most optimal way?

```cpp
#include <bits/stdc++.h>
using namespace std;

cont int MaxN=100005; // Max number of nodes 5

vector <int> adj[MaxN];
bool mark[MaxN];

void bfs(int starting_point,int ending_point) {
    memset(mark,0,sizeof(mark)); //clear the cache
    queue <pair <int,int> > q; // the value of node
    // , and length between this node and the starting node

    q.push_back(make_pair(starting_point,0));
    mark[starting_point]=1;

    while(q.empty()==false) {
        pair <int,int> tmp = q.front(); // get the next node
        q.pop(); // delete from q

        if(ending_point==tmp.first) {
            printf("The length of path between %d - %d : %d\n",
            starting_point,ending_point,tmp.second);
            return;
        }

        for (auto j : adj[tmp.first]) {
            if(mark[j]) continue ; // if it reached before
            mark[j]=1;
            q.push_back(make_pair(j,tmp.second+1)); // add next node to queue
        }
    }
}

int main() {
    cin » n

    for (int i=0 ; i < m; i++) {
        cin » a » b;
        adj[a].push_back(b);
    }

    cin » start_point » end_point;
    bfs(start_point);
    return 0;
}
```

## Complexity

The time complexity of BFS is \(O(V + E)\), where \(V\) is the number of nodes and \(E\) is the number of edges.