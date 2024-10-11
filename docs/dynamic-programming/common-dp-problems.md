---
title: Common Dynamic Programming Problems
tags:
    - Dynamic Programming
    - Common Dynamic Programming Problems
---

## Coin Problem

As discussed earlier, the Greedy approach doesn’t work all the time for the coin problem. For example, if the coins are \{4, 3, 1\} and the target sum is \(6\), the greedy algorithm produces the solution \(4+1+1\), while the optimal solution is \(3+3\). This is where Dynamic Programming (DP) helps.

### Solution

#### Approach:

1. If \( V == 0 \), then 0 coins are required.
2. If \( V > 0 \), compute \( \text{minCoins}(coins[0..m-1], V) = \min \{ 1 + \text{minCoins}(V - \text{coin}[i]) \} \) for all \( i \) where \( \text{coin}[i] \leq V \).

```python
def minCoins(coins, target):
    # base case
    if (V == 0):
        return 0

    n = len(coins)
    # Initialize result
    res = sys.maxsize

    # Try every coin that has smaller value than V
    for i in range(0, n):
        if (coins[i] <= target):
            sub_res = minCoins(coins, target-coins[i])

    # Check for INT_MAX to avoid overflow and see if
    # result can minimized
    if (sub_res != sys.maxsize and sub_res + 1 < res):
        res = sub_res + 1

    return res
```

## Knapsack Problem

We are given the weights and values of \( n \) items, and we are to put these items in a knapsack of capacity \( W \) to get the maximum total value. In other words, we are given two integer arrays `val[0..n-1]` and `wt[0..n-1]`, which represent the values and weights associated with \( n \) items. We are also given an integer \( W \), which represents the knapsack's capacity. Our goal is to find out the maximum value subset of `val[]` such that the sum of the weights of this subset is smaller than or equal to \( W \). We cannot break an item; we must either pick the complete item or leave it.

#### Approach:

There are two cases for every item:
1. The item is included in the optimal subset.
2. The item is not included in the optimal subset.

The maximum value that can be obtained from \( n \) items is the maximum of the following two values:
1. Maximum value obtained by \( n-1 \) items and \( W \) weight (excluding the \( n \)-th item).
2. Value of the \( n \)-th item plus the maximum value obtained by \( n-1 \) items and \( W - \text{weight of the } n \)-th item (including the \( n \)-th item).

If the weight of the \( n \)-th item is greater than \( W \), then the \( n \)-th item cannot be included, and case 1 is the only possibility.

For example:

- Knapsack max weight: \( W = 8 \) units
- Weight of items: \( \text{wt} = \{3, 1, 4, 5\} \)
- Values of items: \( \text{val} = \{10, 40, 30, 50\} \)
- Total items: \( n = 4 \)

The sum \( 8 \) is possible with two combinations: \{3, 5\} with a total value of 60, and \{1, 3, 4\} with a total value of 80. However, a better solution is \{1, 5\}, which has a total weight of 6 and a total value of 90.

### Recursive Solution

```python
def knapSack(W , wt , val , n):

    # Base Case
    if (n == 0 or W == 0):
        return 0

    # If weight of the nth item is more than Knapsack of capacity
    # W, then this item cannot be included in the optimal solution
    if (wt[n-1] > W):
        return knapSack(W, wt, val, n - 1)

    # return the maximum of two cases:
    # (1) nth item included
    # (2) not included
    else:
        return max(val[n-1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1))
```

### Dynamic Programming Solution

It should be noted that the above function computes the same subproblems again and again. Time complexity of this naive recursive solution is exponential \(2^n\).
Since suproblems are evaluated again, this problem has Overlapping Subproblems property. Like other typical Dynamic Programming(DP) problems, recomputations of same subproblems can be avoided by constructing a temporary array \(K[][]\) in bottom up manner. Following is Dynamic Programming based implementation.

```python
def knapSack(W, wt, val, n):
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]

    # Build table K[][] in bottom up manner
    for (i in range(n + 1)):
        for (w in range(W + 1)):
            if (i == 0 or w == 0):
                K[i][w] = 0
            elif (wt[i - 1] <= w):
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]

    return K[n][W]
```

## Longest Common Substring (LCS) Problem

We are given two strings \( X \) and \( Y \), and our task is to find the length of the longest common substring.

### Sample Case:

- Input: \( X = "inzvahackerspace" \), \( Y = "spoilerspoiler" \)
- Output: 4

The longest common substring is "ersp" and is of length 4.

#### Approach:

Let \( m \) and \( n \) be the lengths of the first and second strings, respectively. A simple solution is to consider all substrings of the first string one by one and check if they are substrings of the second string. Keep track of the maximum-length substring. There will be \( O(m^2) \) substrings, and checking if one is a substring of the other will take \( O(n) \) time. Thus, the overall time complexity is \( O(n \cdot m^2) \).

Dynamic programming can reduce this to \( O(m \cdot n) \). The idea is to find the length of the longest common suffix for all substrings of both strings and store these lengths in a table. The longest common suffix has the following property:

\[
LCSuff(X, Y, m, n) = LCSuff(X, Y, m-1, n-1) + 1 \text{ if } X[m-1] = Y[n-1]
\]
Otherwise, \( LCSuff(X, Y, m, n) = 0 \).

The maximum length of the Longest Common Suffix is the Longest Common Substring.

### DP - Iterative

```python
def LCSubStr(X, Y):
    m = len(X)
    n = len(Y)

    # Create a table to store lengths of
    # longest common suffixes of substrings.
    # Note that LCSuff[i][j] contains the
    # length of longest common suffix of
    # X[0...i−1] and Y[0...j−1]. The first
    # row and first column entries have no
    # logical meaning, they are used only
    # for simplicity of the program.

    # LCSuff is the table with zero
    # value initially in each cell
    LCSuff = [[0 for k in range(n+1)] for l in range(m + 1)]

    # To store the length of
    # longest common substring
    result = 0

    # Following steps to build
    # LCSuff[m+1][n+1] in bottom up fashion
    for (i in range(m + 1)):
        for (j in range(n + 1)):
    if (i == 0 or j == 0):
                LCSuff[i][j] = 0
            elif (X[i - 1] == Y[j - 1]):
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1
                result = max(result, LCSuff[i][j])
            else:
                LCSuff[i][j] = 0
    return result
```

### DP - Recursive

```python
def lcs(int i, int j, int count):
    if (i == 0 or j == 0):
        return count

    if (X[i - 1] == Y[j - 1]):
        count = lcs(i - 1, j - 1, count + 1)

    count = max(count, max(lcs(i, j - 1, 0), lcs(i - 1, j, 0)))
    return count
```

## Longest Increasing Subsequence (LIS) Problem

The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

For example, given the array \([0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]\), the longest increasing subsequence has a length of 6, and it is \{0, 2, 6, 9, 11, 15\}.

### Solution

A naive, brute-force approach is to generate every possible subsequence, check for monotonicity, and keep track of the longest one. However, this is prohibitively expensive, as generating each subsequence takes \( O(2^N) \) time.

Instead, we can use recursion to solve this problem and then optimize it with dynamic programming. We assume that we have a function that gives us the length of the longest increasing subsequence up to a certain index.

The base cases are:
- The empty list, which returns 0.
- A list with one element, which returns 1.

For every index \( i \), calculate the longest increasing subsequence up to that point. The result can only be extended with the last element if the last element is greater than \( \text{arr}[i] \), as otherwise, the sequence wouldn’t be increasing.

```python
def longest_increasing_subsequence(arr):
    if (not arr):
        return 0
    if (len(arr) == 1):
        return 1

    max_ending_here = 0
    for (i in range(len(arr))):
        ending_at_i = longest_increasing_subsequence(arr[:i])
        if (arr[-1] > arr[i - 1] and ending_at_i + 1 > max_ending_here):
            max_ending_here = ending_at_i + 1
    return max_ending_here
```

This is really slow due to repeated subcomputations (exponential in time). So, let’s use dynamic
programming to store values to recompute them for later.

We’ll keep an array A of length N, and A[i] will contain the length of the longest increasing subsequence ending at i. We can then use the same recurrence but look it up in the array instead:

```python
def longest_increasing_subsequence(arr):
    if (not arr):
        return 0
    cache = [1] * len(arr)
    for (i in range(1, len(arr))):
        for (j in range(i)):
            if (arr[i] > arr[j]):
                cache[i] = max(cache[i], cache[j] + 1)
    return max(cache)
```

This now runs in \( O(N^2) \) time and \( O(N) \) space.