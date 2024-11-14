---
title: Graph Definitions
tags:
    - Graph
---

## Definitions of Common Terms

- **Node** - An individual data element of a graph is called Node. Node is also known as vertex.
- **Edge** - An edge is a connecting link between two nodes. It is represented as e = {a,b} Edge is also called Arc.
- **Adjacent** - Two vertices are adjacent if they are connected by an edge.
- **Degree** - a degree of a node is the number of edges incident to the node.
- **Undirected Graphs** - Undirected graphs have edges that do not have a direction. The edges indicate a two-way relationship, in that each edge can be traversed in both directions.
- **Directed Graphs** - Directed graphs have edges with direction. The edges indicate a one-way relationship, in that each edge can only be traversed in a single direction.
- **Weighted Edges** - If each edge of graphs has an association with a real number, this is called its weight.
- **Self-Loop** - It is an edge having the same node for both destination and source point.
- **Multi-Edge** - Some Adjacent nodes may have more than one edge between each other.

## Walks, Trails, Paths, Cycles and Circuits

- **Walk** - A sequence of nodes and edges in a graph.
- **Trail** - A walk without visiting the same edge.
- **Circuit** - A trail that has the same node at the start and end.
- **Path** - A walk without visiting same node.
- **Cycle** - A circuit without visiting same node. 

## Special Graphs

- **Complete Graph** - A graph having at least one edge between every two nodes.
- **Connected Graph** - A graph with paths between every pair of nodes.
- **Tree** - an undirected connected graph that has any two nodes that are connected by exactly one path. There are some other definitions that you can notice it is tree:
    - an undirected graph is connected and has no cycles. an undirected graph is acyclic, and a simple cycle is formed if any edge is added to the graph.
    - an undirected graph is connected, it will become disconnected if any edge is removed.
    - an undirected graph is connected, and has  (number of nodes - 1) edges.
