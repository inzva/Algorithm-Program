---
title: DP on Rooted Trees
tags:
    - Dynamic Programming
    - DP on Rooted Trees
---

In dynamic programming (DP) on rooted trees, we define functions for the nodes of the tree, which are calculated recursively based on the children of each node. One common DP state is usually associated with a node \(i\), representing the sub-tree rooted at node \(i\).

---

## Problem

Given a tree \( T \) of \( N \) (1-indexed) nodes, where each node \( i \) has \( C_i \) coins attached to it, the task is to choose a subset of nodes such that no two adjacent nodes (nodes directly connected by an edge) are chosen, and the sum of coins attached to the chosen subset is maximized.

### Approach:

We define two functions, \( dp1(V) \) and \( dp2(V) \), as follows:

- \( dp1(V) \): The optimal solution for the sub-tree of node \( V \) when node \( V \) **is included** in the answer.
- \( dp2(V) \): The optimal solution for the sub-tree of node \( V \) when node \( V \) **is not included** in the answer.

The final answer is the maximum of these two cases:

\[
\text{max}(dp1(V), dp2(V))
\]

### Recursive Definitions:

- \( dp1(V) = C_V + \sum_{i=1}^{n} dp2(v_i) \), where \( n \) is the number of children of node \( V \), and \( v_i \) is the \( i \)-th child of node \( V \).  
  This represents the scenario where node \( V \) is included in the chosen subset, so none of its children can be selected.

- \( dp2(V) = \sum_{i=1}^{n} \text{max}(dp1(v_i), dp2(v_i)) \).  
  This represents the scenario where node \( V \) is not included, so the optimal solution for each child \( v_i \) can either include or exclude that child.

### Complexity:

The time complexity for this approach is \( O(N) \), where \( N \) is the number of nodes in the tree. This is because the solution involves a depth-first search (DFS) traversal of the tree, and each node is visited only once.

```cpp
//pV is parent of V
void dfs(int V, int pV)
{
    //base case:
    //when dfs reaches a leaf it finds dp1 and dp2 and does not branch again.

    //for storing sums of dp1 and max(dp1, dp2) for all children of V
    int sum1 = 0, sum2 = 0;

    //traverse over all children
    for (auto v : adj[V])
    {
        if (v == pV)
            continue;
        dfs(v, V);
        sum1 += dp2[v];
        sum2 += max(dp1[v], dp2[v]);
    }

    dp1[V] = C[V] + sum1;
    dp2[V] = sum2;
}
//Nodes are 1-indexed, therefore our answer stored in dp1[1] and dp2[1]
//for the answer we take max(dp1[1],dp2[1]) after calling dfs(1,0).
```

---

## References

- [DP on Tree on CodeForces](https://codeforces.com/blog/entry/20935)