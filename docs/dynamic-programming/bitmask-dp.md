---
title: Bitmask DP
tags:
    - Dynamic Programming
    - Bitmask DP
---

## What is Bitmask?

Let’s say that we have a set of objects. How can we represent a subset of this set? One way is using a map and mapping each object with a Boolean value indicating whether the object is picked. Another way is, if the objects can be indexed by integers, we can use a Boolean array. However, this can be slow due to the operations of the map and array structures. If the size of the set is not too large (less than 64), a bitmask is much more useful and convenient.

An integer is a sequence of bits. Thus, we can use integers to represent a small set of Boolean values. We can perform all the set operations using bit operations. These bit operations are faster than map and array operations, and the time difference may be significant in some problems.

In a bitmask, the \( i \)-th bit from the right represents the \( i \)-th object. For example, let \( A = \{1, 2, 3, 4, 5\} \), we can represent \( B = \{1, 2, 4\} \) with the 11 (01011) bitmask.

---

## Bitmask Operations

- **Add the \( i \)-th object to the subset:**  
  Set the \( i \)-th bit to 1:  
  \( \text{mask } = \text{mask } | \text{ } (1 << i) \)

- **Remove the \( i \)-th object from the subset:**  
  Set the \( i \)-th bit to 0:  
  \( \text{mask } = \text{mask } \& \sim (1 << i) \)

- **Check whether the \( i \)-th object is in the subset:**  
  Check if the \( i \)-th bit is set:  
  \( \text{mask } \& \text{ } (1 << i) \).  
  If the expression is equal to 1, the \( i \)-th object is in the subset. If the expression is equal to 0, the \( i \)-th object is not in the subset.

- **Toggle the existence of the \( i \)-th object:**  
  XOR the \( i \)-th bit with 1, turning 1 into 0 and 0 into 1:  
  \( \text{mask} = \text{mask}\)  ^ \( (1 << i) \)

- **Count the number of objects in the subset:**  
  Use a built-in function to count the number of 1’s in an integer variable:  
  `__builtin_popcount(mask)` for integers or `__builtin_popcountll(mask)` for long longs.

---

## Iterating Over Subsets

- **Iterate through all subsets of a set with size \( n \):**  
  \( \text{for (int x = 0; x < (1 << n); ++x)} \)

- **Iterate through all subsets of a subset with the mask \( y \):**  
  \( \text{for (int x = y; x > 0; x = (y \& (x − 1)))} \)

---

## Task Assignment Problem

There are \( N \) people and \( N \) tasks, and each task is going to be allocated to a single person. We are also given a matrix `cost` of size \( N \times N \), where `cost[i][j]` denotes how much a person is going to charge for a task. We need to assign each task to a person such that the total cost is minimized. Note that each task is allocated to only one person, and each person is allocated only one task.

### Naive Approach:

Try \( N! \) possible assignments.  
**Time complexity:** \( O(N!) \).

### DP Approach:

For every possible subset, find the new subsets that can be generated from it and update the DP array. Here, we use bitmasking to represent subsets and iterate over them.  
**Time complexity:** \( O(2^N \times N) \).

**Note:** The [Hungarian Algorithm](https://en.wikipedia.org/wiki/Hungarian_algorithm) solves this problem in \( O(N^3) \) time complexity.

Solution code for DP approach:

```cpp
for (int mask = 0; mask < (1 << n); ++mask)
{
    for (int j = 0; j < n; ++j)
    {
        if((mask & (1 << j)) == 0) // jth task not assigned
        {
            dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[__builtin_popcount(mask)][j])
        }
    }
}
// after this operation our answer stored in dp[(1 << N) - 1]
```

---

## References

- [Bitmask Tutorial on HackerEarth](https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/tutorial/)