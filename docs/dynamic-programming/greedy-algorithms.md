---
title: Greedy Algorithms
tags:
    - Dynamic Programming
    - Greedy Algorithms
---

A *greedy algorithm* is an algorithm that follows the problem solving heuristic of making the locally optimal choice at each stage with the hope of finding a global optimum. A greedy algorithm never takes back its choices, but directly constructs the final solution. For this reason, greedy algorithms are usually very efficient.

The difficulty in designing greedy algorithms is to find a greedy strategy that always produces an optimal solution to the problem. The locally optimal choices in a greedy algorithm should also be globally optimal. It is often difficult to argue that a greedy algorithm works.

## Coin Problem

We are given a value \( V \). If we want to make change for \( V \) cents, and we have an infinite supply of each of the coins = { \( C_1, C_2, \dots, C_m \) } valued coins (sorted in descending order), what is the minimum number of coins to make the change?

### Solution

#### Approach:

1. Initialize the result as empty.
2. Find the largest denomination that is smaller than the amount.
3. Add the found denomination to the result. Subtract the value of the found denomination from the amount.
4. If the amount becomes 0, then print the result. Otherwise, repeat steps 2 and 3 for the new value of the amount.

```python
def min_coins(coins, amount):
    n = len(coins)
    for i in range(n):
        while amount >= coins[i]:
            # while loop is needed since one coin can be used multiple times
            amount -= coins[i]
            print(coins[i])
```
For example, if the coins are the euro coins (in cents) \({200, 100, 50, 20, 10, 5, 2, 1}\) and the amount is 548, the optimal solution is to select coins \(200+200+100+20+20+5+2+1\), whose sum is \(548\).

<figure markdown="span">
![Coin Change Problem](img/coin_change.png){ width="90%" }
<figcaption>Visualization of the Coin Change Problem</figcaption>
</figure>

In the general case, the coin set can contain any kind of coins, and the greedy algorithm does not necessarily produce an optimal solution.

We can prove that a greedy algorithm does not work by showing a counterexample where the algorithm gives a wrong answer. In this problem, we can easily find a counterexample: if the coins are \({6, 5, 2}\) and the target sum is \(10\), the greedy algorithm produces the solution \(6+2+2\), while the optimal solution is \(5+5\).

## Scheduling

Many scheduling problems can be solved using greedy algorithms. A classic problem is as follows:

We are given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes a single unit of time, thus the minimum possible deadline for any job is 1. How do we maximize total profit if only one job can be scheduled at a time?

### Solution

A simple solution is to generate all subsets of the given set of jobs and check each subset for feasibility. Keep track of maximum profit among all feasible subsets. The time complexity of this solution is exponential. This is a standard Greedy Algorithm problem.

#### Approach:

1. Sort all jobs in decreasing order of profit.
2. Initialize the result sequence as the first job in sorted jobs.
3. For the remaining \(n-1\) jobs:
   - If the current job can fit in the current result sequence without missing the deadline, add the current job to the result.
   - Else ignore the current job.

```python
# sample job : ['x', 4, 25] −> [job_id, deadline, profit]
# jobs: array of 'job's
def print_job_scheduling(jobs, t):
    n = len(jobs)
    
    # Sort all jobs according to decreasing order of profit
    for i in range(n):
        for j in range(n - 1 - i):
            if jobs[j][2] < jobs[j + 1][2]:
                jobs[j], jobs[j + 1] = jobs[j + 1], jobs[j]
    
    # To keep track of free time slots
    result = [False] * t
    # To store result (Sequence of jobs)
    job = ['-1'] * t
    
    # Iterate through all given jobs
    for i in range(len(jobs)):
        # Find a free slot for this job
        # (Note that we start from the last possible slot)
        for j in range(min(t - 1, jobs[i][1] - 1), -1, -1):
            # Free slot found
            if result[j] is False:
                result[j] = True
                job[j] = jobs[i][0]
                break
    print(job)
```

## Tasks and Deadlines

Let us now consider a problem where we are given \(n\) tasks with durations and deadlines, and our task is to choose an order to perform the tasks. For each task, we earn \(d - x\) points, where \(d\) is the task’s deadline and \(x\) is the moment when we finish the task. What is the largest possible total score we can obtain?

For example, suppose the tasks are as follows:

| Task | Duration | Deadline |
|------|----------|----------|
| A    | 4        | 2        |
| B    | 3        | 5        |
| C    | 2        | 7        |
| D    | 4        | 5        |

An optimal schedule for the tasks is \( C, B, A, D \). In this solution, \( C \) yields 5 points, \( B \) yields 0 points, \( A \) yields -7 points, and \( D \) yields -8 points, so the total score is -10.

Interestingly, the optimal solution to the problem does not depend on the deadlines, but a correct greedy strategy is to simply perform the tasks sorted by their durations in increasing order.

### Solution

1. Sort all tasks according to increasing order of duration.
2. Calculate the total points by iterating through all tasks, summing up the difference between the deadlines and the time at which the task is finished.

```python
def order_tasks(tasks):
    n = len(tasks)

    # Sort all task according to increasing order of duration
    for (i in range(n)):
        for (j in range(n - 1 - i)):
            if (tasks[j][1] > tasks[j + 1][1]):
                tasks[j], tasks[j + 1] = tasks[j + 1], tasks[j]

    point = 0
    current_time = 0
    # Iterate through all given tasks and calculate point
    for (i in range(len(tasks))):
        current_time = current_time + tasks[i][1]
        point = point + (tasks[i][2] - current_time)

    print(point)
```

## Minimizing Sums

We are given \(n\) numbers and our task is to find a value \(x\) that minimizes the sum:

\[
|a_1 − x|^c + |a_2 − x|^c + ... + |a_n − x|^c
\]

We focus on the cases \(c = 1\) and \(c = 2\).

### Case \(c = 1\)

In this case, we should minimize the sum:

\[
|a_1 − x| + |a_2 − x| + ... + |a_n − x|
\]

For example, if the numbers are \([1, 2, 9, 2, 6]\), the best solution is to select \(x = 2\), which produces the sum:

\[
|1 − 2| + |2 − 2| + |9 − 2| + |2 − 2| + |6 − 2| = 12
\]

In the general case, the best choice for \(x\) is the median of the numbers. For instance, the list \([1, 2, 9, 2, 6]\) becomes \([1, 2, 2, 6, 9]\) after sorting, so the median is 2. The median is an optimal choice because if \(x\) is smaller than the median, the sum decreases by increasing \(x\), and if \(x\) is larger, the sum decreases by lowering \(x\). Hence, the optimal solution is \(x = \text{median}\).

### Case \(c = 2\)

In this case, we minimize the sum:

\[
(a_1 − x)^2 + (a_2 − x)^2 + ... + (a_n − x)^2
\]

For example, if the numbers are \([1, 2, 9, 2, 6]\), the best solution is to select \(x = 4\), which produces the sum:

\[
(1 − 4)^2 + (2 − 4)^2 + (9 − 4)^2 + (2 − 4)^2 + (6 − 4)^2 = 46
\]

In the general case, the best choice for \(x\) is the average of the numbers. For the given example, the average is:

\[
\frac{(1 + 2 + 9 + 2 + 6)}{5} = 4
\]

This result can be derived by expressing the sum as:

\[
n x^2 − 2x(a_1 + a_2 + ... + a_n) + (a_1^2 + a_2^2 + ... + a_n^2)
\]

The last part does not depend on \(x\), so we can ignore it. The remaining terms form a function with a parabola opening upwards, and the minimum value occurs at \(x = \frac{s}{n}\), where \(s\) is the sum of the numbers, i.e., the average of the numbers.