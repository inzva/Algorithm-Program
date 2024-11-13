---
title: Union Find
tags:
    - Graph
    - Union Find
    - Disjoint Set Union
    - DSU
---

A disjoint-set data structure is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets. A union-find algorithm is an algorithm that performs two useful operations on such a data structure: [11, 12]

- Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
- Union: Join two subsets into a single subset
- Union-Find Algorithm can be used to check whether an undirected graph contains cycle or not. This is another method based on Union-Find. This method assumes that graph doesn’t contain any self-loops. 
- Most commonly used in kruskal's minumum spanning tree algorithm, it is used to check whether two nodes are in same connected component or not. [10]

## Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

cont int MaxN=100005; // Max number of nodes

int ancestor[MaxN];

int parent(int k) // return the ancestor
{
    if(ancestor[k]==k) return k;
    return ancestor[k] = parent(ancestor[k]); 
    // do not forget to equlize ancestor[k], it is going to decrease time complexity for the next operations
}

int MakeUnion(int a,int b) // setting parent of root(a) as root(b).
{
    a = parent(a);
    b= parent(b);
    ancestor[a] = b;
}
int find(int a,int b)
{
    return parent(a)==parent(b);
}
```

## Complexity

Using both path compression, splitting, or halving and union by rank or size ensures that the amortized time per operation is only $\mathcal{O}(\alpha (n))$, which is optimal, where $\alpha (n)$ is the inverse Ackermann function. This function has a value $\alpha (n)<5$ for any value of n that can be written in this physical universe, so the disjoint-set operations take place in essentially constant time.
