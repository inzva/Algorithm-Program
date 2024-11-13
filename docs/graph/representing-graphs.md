---
title: Representing Graphs
tags:
    - Graph
---

## Edge Lists

A simple way to define edge list is that it has a list of pairs. We just have a list of objects consisting of the vertex numbers of 2 nodes and other attributes like weight or the direction of edges. [16]

- **\+** For some specific algorithms you need to iterate over all the edges, (i.e. kruskal's algorithm)
- **\+** All edges are stored exactly once.
- **\-** It is hard to determine whether two nodes are connected or not.
- **\-** It is hard to get information about the edges of a specific vertex.

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int edge_number;
    vector<pair <int,int> > edges;
    cin >> edge_number;
    for( int i=0 ; i<edge_number ; i++ ){
        int a,b;
        cin >> a >> b;
        edges.push_back(make_pair(a,b)); // a struct can be used if edges are weighted or have other properties.
    }
}
```

## Adjacency Matrices

Stores edges, in a 2-D matrix. matrix[a][b] keeps an information about road from a to b. [16]
- **\+** We can easily check if there is a road between two vertices.
- **\-** Looping through all edges of a specific node is expensive because you have to check all of the empty cells too. Also these empty cells takes huge memory in a graph which has many vertices. (For example representing a tree)

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int node_number;
    vector<vector<int> > Matrix;
    cin >> node_number;
    for( int i=0 ; i<node_number ; i++ )
        for( int j=0 ; j<node_number ; j++ ){
            Matrix.push_back(vector <int> ());
            int weight;
            cin >>weight ;
            Matrix[i].push_back(weight);
        }
}
```

## Adjacency List

Each node has a list consisting of nodes each is adjacent to. So, there will be no empty cells. Memory will be equal to number of edges. The most used one is in algorithms. [16]

- **\+** You do not have to use space for empty cells.
- **\+** Easily iterate over all the neighbors of a specific node.
- **\-** If you want to check if two nodes are connected, in this form you still need to iterate over all the neighbors of one of them. But, there are some structures that you can do this operation in O(log N). For example if you won't add any edge, you can sort every vector with nodes' names, so you can find it by binary search.  

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int node_number,path_number;

    vector<vector<int> > paths; 
    // use object instead of int, 
    //if you need to store other features

    cin >> node_number >> path_number;
    for( int i=0 ; i<node_number ; i++ )
        Matrix.push_back(vector <int> ());
    for( int j=0 ; j< path_number ; j++ ){
        int beginning_node, end_node;
        cin >> beginning_node >> end_node;

        Matrix[ beginning_node ].push_back( end_node ); // push st
        // Matrix[ end_node ].push_back(  beginning_node ); 
        // ^^^ If edges are Undirected, you should push in reverse direction too
    }
}
```