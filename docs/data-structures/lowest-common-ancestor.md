---
title: Lowest Common Ancestors
tags:
    - Tree
    - LCA
    - Lowest Common Ancestors
    - Binary Lifting
---

This problem consists of queries, LCA(x, y), and asks for the ancestor of both x and y whose depth is maximum. We will use a similar algorithm to the jump pointer algorithm with implementation.

## Initialization

As we did in Jump Pointer Method, we will calculate node's all $2^i$. ancestors if they exist. L[x][y] corresponds to x's $2^y$. ancestors. Hence L[x][0] is basically the parent of x.

```cpp
void init() {
    for(int x=1 ; x<=n ; x++)
        L[x][0] = parent[x];

    for(int y=1 ; y<=logN ; y++)
        for(int x=1 ; x<=n ; x++)
            L[x][y] = L[L[x][y-1]][y-1];
}
```
Note that we have used the fact that x's $2^y$. ancestor is x's $2^{y−1}$. ancestor's $2^{y−1}$. ancestor.

## Queries-Binary Lifting

Given LCA(x, y), we calculate answer by following:

Firstly, ensure that both x and y are in same depth. If it is not take the deepest one to the other one's depth. Then control whether x and y is equal. If they are equal, that means the lowest common ancestor is x. After that, from i = log(N), check that if x's $2^i$. ancestor is equal to y's $2^i$. ancestor. If they are not equal that means LCA is somewhere above the $2^i$. ancestors of x and y. Then we continue to search LCA of y and x’s ancestors as LCA(L[x][i], L[y][i]) is the same as LCA(x, y). Please notice that we have ensured that depth diﬀerence between LCA and both x and y are no longer larger than $2^i$. If we apply this producure until i = 0, we would left with x and y such that parent of x is LCA. Of course, the parent of y would also be LCA.
