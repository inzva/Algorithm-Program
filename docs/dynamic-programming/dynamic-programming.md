---
title: Dynamic Programming
tags:
    - Dynamic Programming
---

Dynamic programming (DP) is a technique used to avoid computing the same sub-solution multiple times in a recursive algorithm. A sub-solution of the problem is constructed from the previously found ones. DP solutions have a polynomial complexity, which ensures a much faster running time than other techniques like backtracking or brute-force.

## Memoization - Top Down

Memoization ensures that a method doesn’t run for the same inputs more than once by keeping a record of the results for the given inputs (usually in a hash map). 

To avoid duplicate work caused by recursion, we can use a cache that maps inputs to outputs. The approach involves:

- Checking the cache to see if we can avoid computing the answer for any given input.
- Saving the results of any calculations to the cache.

Memoization is a common strategy for dynamic programming problems where the solution is composed of solutions to the same problem with smaller inputs, such as the Fibonacci problem.

Another strategy for dynamic programming is the **bottom-up** approach, which is often cleaner and more efficient.

## Bottom-Up

The bottom-up approach avoids recursion, saving the memory cost associated with building up the call stack. It "starts from the beginning" and works towards the final solution, whereas a recursive algorithm often "starts from the end and works backwards."

## An Example - Fibonacci

Let’s start with a well-known example: finding the \(n\)-th Fibonacci number. The Fibonacci sequence is defined as:

\[
F_n = F_{n−1} + F_{n−2}, \quad \text{with } F_0 = 0 \text{ and } F_1 = 1
\]

There are several approaches to solving this problem:

### Recursion

In a recursive approach, the function calls itself to compute the previous two Fibonacci numbers until reaching the base cases.

```python
def fibonacci(n):
    if (n == 0):
        return 0
    if (n == 1):
        return 1

    return fibonacci(n - 1) + fibonacci(n - 2)
```

### Dynamic Programming

- **Top-Down - Memoization:**
  Recursion leads to unnecessary repeated calculations. Memoization solves this by caching the results of previously computed Fibonacci numbers, so they don't have to be recalculated.

```python
cache = {}

def fibonacci(n):
    if (n == 0):
        return 0
    if (n == 1):
        return 1
    if (n in cache):
        return cache[n]

    cache[n] = fibonacci(n - 1) + fibonacci(n - 2)

    return cache[n]
```

<figure markdown="span">
![Recursive vs Memoization](img/recursive_memoization.png){ width="90%" }
<figcaption>Visualization of Recursive Memoization</figcaption>
</figure>


- **Bottom-Up:**
  The bottom-up approach eliminates recursion by computing the Fibonacci numbers in order, starting from the base cases and building up to the desired value.

```python
cache = {}

def fibonacci(n):
    cache[0] = 0
    cache[1] = 1

    for (i in range(2, n + 1)):
        cache[i] = cache[i - 1] + cache[i - 2]

    return cache[n]
```

Additionally, this approach can be optimized further by using constant space and only storing the necessary partial results along the way.

```python
def fibonacci(n):
    fib_minus_2 = 0
    fib_minus_1 = 1

    for (i in range(2, n + 1)):
        fib = fib_minus_1 + fib_minus_2
        fib_minus_1, fib_minus_2 = fib, fib_minus_1

    return fib
```

## How to Apply Dynamic Programming?

To apply dynamic programming, follow these steps:

- **Find the recursion in the problem:** Identify how the problem can be broken down into smaller subproblems.
- **Top-down approach:** Store the result of each subproblem in a table to avoid recomputation.
- **Bottom-up approach:** Find the correct order to evaluate the results so that partial results are available when needed.

Dynamic programming generally works for problems that have an inherent left-to-right order, such as strings, trees, or integer sequences. If the naive recursive algorithm does not compute the same subproblem multiple times, dynamic programming won't be useful.