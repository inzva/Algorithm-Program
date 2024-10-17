---
title: Topological Sort
tags:
    - Graph
    - Topological Sort
---

## Definition


Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u->v, vertex u comes before v in the ordering. Topological Sorting for a graph is not possible if the graph is not a DAG [6].

There are many important usages of topological sorting in computer science; applications of this type arise in instruction scheduling, ordering of formula cell evaluation when recomputing formula values in spreadsheets, logic synthesis, determining the order of compilation tasks to perform in makefiles, data serialization, and resolving symbol dependencies in linkers. It is also used to decide in which order to load tables with foreign keys in databases [7].

There are known algorithms (e.g Kahn’s algorithm) to find topological order in linear time. Below, you can find one of the implementations:

<figure markdown="span">
![Topological Order](img/toporder.png)
<figcaption>For example, a topological sorting of this graph is “5 4 2 3 1 0”. There can be more than one topological sorting for a graph. For example, another topological sorting of the following graph is “4 5 2 3 1 0”. The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges)[6].</figcaption>
</figure>

## Algorithm

```cpp
typedef vector<int> adjList;
typedef vector<adjList> graph;
typedef pair<int,int> ii;

void kahn(graph &g) {
    vector<int> result;
    queue<int> q;
    vector<int> degree(g.size(),0); // number of incoming egdes.
    for(auto &list: g){
        for(auto &node:list) {
            degree[node]++;
        } 
    }

    for(int i=0; i < g.size(); ++i) {
        if (degree[i] == 0)
        q.push(i);
    }

    while( !q.empty()) {
        int node = q.front();
        result.push_back(node);
        q.pop();

        for (auto &ng: g[node]) {
            degree[ng]--;
            if (degree[ng] == 0)
                q.push(ng); 
        }
    }

    for(auto &i:result)
        cout << i << " ";
    cout << endl;
}
int main(){
    graph g(6);
    g[1].push_back(0);
    g[1].push_back(2);
    g[2].push_back(3);
    g[3].push_back(4);
    g[4].push_back(5);
    kahn(g);
    return 0; 
}
```

As for time complexity: we traverse all edges in the beginning (calculating degrees) and in the while segment we remove edges (once for an edge) and traverse all nodes. Hence, the time complexity of this algorithm is \(O(V +E)\). Note that this implementation assumes the graph is DAG. Try improving this code to support checking if the graph is DAG!
