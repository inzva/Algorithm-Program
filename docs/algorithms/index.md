---
title: Algorithms
tags:
    - Algorithms
    - Linear Search
    - Binary Search
    - Ternary Search
    - Sorting Algorithms
    - Insertion Sort
    - Merge Sort
    - Quick Sort
    - Radix Sort
    - Quickselect Algorithm
    - Divide and Conquer
---

**Editor:** Kadir Emre Oto

**Reviewers:** Muhammed Burak Buğrul, Tahsin Enes Kuru

## Search Algorithms

It may be necessary to determine if an array or solution set contains a specific data, and we call this finding proccess **searching**. In this article, three most common search algorithms will be discussed: linear search, binary search, and ternary search.

[This visualization](https://www.cs.usfca.edu/~galles/visualization/Search.html){target="_blank"} may help you understand how the search algorithms work.

### Linear Search

Simplest search algorithm is *linear search*, also know as *sequential search*. In this technique, all elements in the collection of the data is checked one by one, if any element matches, algorithm returns the index; otherwise, it returns $-1$.

Its time complexity is $\mathcal{O}(N)$.

<figure markdown="span">
![Example for linear search](img/linear_search.png){ width="90%" }
<figcaption>Example for linear search</figcaption>
</figure>

```c++
int linearSearch(int *array, int size, int key) {
    for (int i = 0; i < size; i++)
        if (array[i] == key)
            return i;
    return -1;
}
```

### Binary Search

We know linear search is quite a slow algorithm because it compares each element of the set with search key, and there is a high-speed searching technique for **sorted** data instead of linear search, which is **binary search**. After each comparison, the algorithm eliminates half of the data using the sorting property. 

We can also use binary search on increasing functions in the same way. 

#### Procedure

1. Compare the key with the middle element of the array,
2. If it is a match, return the index of middle.
3. If the key is bigger than the middle, it means that the key must be in the right side of the middle. We can eliminate the left side.
4. If the key is smaller, it should be on the left side. The right side can be ignored.

#### Complexity

$$
\begin{align*}
T(N) &= T\left(\tfrac{N}{2}\right) + \mathcal{O}(1) \\
T(N) &= \mathcal{O}(\log N)
\end{align*}
$$

<figure markdown="span">
![Example for binary search](img/binary_search.png){ width="90%" }
<figcaption>Example for binary search</figcaption>
</figure>

```c++
int binarySearch(int *array, int size, int key) {
    int left = 0, right = size, mid;

    while (left < right) {
        mid = (left + right) / 2;

        if (array[mid] >= key)
            right = mid;
        else
            left = mid + 1;
    }
    return array[left] == key ? left : -1;
}
```

### Ternary Search

Suppose that we have a [unimodal](https://www.geeksforgeeks.org/mathematics-unimodal-functions-bimodal-functions/){target="_blank"} function, $f(x)$, on an interval $[l, r]$, and we are asked to find the local minimum or the local maximum value of the function according to the behavior of it.

There are two types of unimodal functions:

1. The function, $f(x)$ strictly increases for $x \leq m$, reaches a global maximum at $x = m$, and then strictly decreases for $m \leq x$. There are no other local maxima.

2. The function, $f(x)$ strictly decreases for $x \leq m$, reaches a global minimum at $x = m$, and then strictly increases for $m \leq x$. There are no other local minima.

In this document, we will implement the first type of unimodal function, and the second one can be solved using the same logic.

#### Procedure

1. Choose any two points $m_1$, and $m_2$ on the interval $[l, r]$, where $l < m_1 < m_2 < r$.
2. If $f(m_1) < f(m_2)$, it means the maxima should be in the interval $[m_1, r]$, so we can ignore the interval $[l, m_1]$, move $l$ to $m_1$
3. Otherwise, $f(m_1) \geq f(m_2)$, the maxima have to be in the interval $[l, m_2]$, move $r$ to $m_2$
4. If $r - l < \epsilon$, where $\epsilon$ is a negligible value, stop the algorithm, return $l$. Otherwise turn to the step 1. 

$m_1$ and $m_2$ can be selected by $m_1 = l + \frac{r-l}{3}$ and $m_2 = r - \frac{r-l}{3}$ to avoid increasing the time complexity.

#### Complexity

$$
\begin{align*}
T(N) &= T\left(2 \cdot \tfrac{N}{3}\right) + \mathcal{O}(1) \\
T(N) &= \mathcal{O}(\log N)
\end{align*}
$$

<figure markdown="span">
![Example for ternary search](img/ternary_search.png)
<figcaption>Example for ternary search</figcaption>
</figure>

```c++
double f(double x);

double ternarySearch(double left, double right, double eps = 1e-7) {
    while (right - left > eps) {
        double mid1 = left + (right - left) / 3;
        double mid2 = right - (right - left) / 3;

        if (f(mid1) < f(mid2))
            left = mid1;
        else
            right = mid2;
    }
    return f(left);
}
```

## Sorting Algorithms

Sorting algorithms are used to put the elements of an array in a certain order according to the comparison operator. Numerical order or lexicographical orders are the most common ones, and there are a large number of sorting algorithms, but we discuss four of them:

- *Insertion Sort*
- *Merge Sort*
- *Quick Sort*
- *Radix Sort*

For a better understanding, you are strongly recommended to go into [this visualization site](https://visualgo.net/en/sorting){target="_blank"} after reading the topics.

### Insertion Sort

Think that you are playing a card game and want to sort them before the game. Your sorting strategy is simple: you have already sorted some part and every time you pick up the next card from unsorted part, you insert it into the correct place in sorted part. After you apply this process to all cards, the whole deck would be sorted.

This is the basic idea for sorting an array. We assume that the first element of the array is the sorted part, and other elements are in the unsorted part. Now, we choose the leftmost element of the unsorted part, and put it into the sorted part. In this way the left part of the array always remains sorted after every iteration, and when no element is left in the unsorted part, the array will be sorted. 

```c++
void insertionSort(int *ar, int size) {
    for (int i = 1; i < size; i++)
        for (int j = i - 1; 0 <= j and ar[j] > ar[j + 1]; j--)
            swap(ar[j], ar[j + 1]);
}
```

### Merge Sort

*Merge Sort* is one of the fastest sorting algorithms that uses *Divide and Conquer* paradigm. The algorithm **divides** the array into two halves, solves each part **recursively** using same sorting function and **combines** them in linear time by selecting the smallest value of the arrays every time.

#### Procedure

1. If the size of the array is 1, it is sorted already, stop the algorithm (base case),
2. Find the middle point of the array, and split it in two,
3. Do the algorithm for these parts separately from the first step,
4. After the two halves got sorted, merge them in linear time and the array will be sorted. 

#### Complexity

$$
\begin{align*}
T(N) &= T\left(\tfrac{N}{2}\right) + \mathcal{O}(N) \\
T(N) &= \mathcal{O}(N \cdot \log N)
\end{align*}
$$

```c++
void mergeSort(int *ar, int size) {
    if (size <= 1) // base case
        return;

    mergeSort(ar, size / 2); // divide the array into two almost equal parts
    mergeSort(ar + size / 2, size - size / 2);

    int index = 0, left = 0, right = size / 2; // merge them
    int *temp = new int[size];

    while (left < size / 2 or right < size) {
        if (right == size or (left < size / 2 and ar[left] < ar[right]))
            temp[index++] = ar[left++];
        else
            temp[index++] = ar[right++];
    }
    for (int i = 0; i < size; i++)
        ar[i] = temp[i];
    delete[] temp;
}
```

### Quick Sort

*Quick Sort* is also a *Divide and Conquer* algorithm. The algorithm chooses an element from the array as a pivot and partitions the array around it. Partitioning is arranging the array that satisfies those: the pivot should be put to its correct place, all smaller values should be placed before the pivot, and all greater values should be placed after the pivot. The partitioning can be done in linear time, and after the partitioning, we can use the same sorting function to solve the left part of the pivot and the right part of the pivot recursively.

If the sellected pivot cannot divide the array uniformly after the partitioning, the time complexity can reach $\mathcal{O}(n ^ 2)$ like insertion sort. To avoid this, the pivot can generally be picked randomly.

#### Procedure

1. If the size of the array is $1$, it is sorted already, stop the algorithm (base case),
2. Choose a pivot randomly,
3. For all values in the array, collect smaller values in the left of the array and greater values in the right of array,
4. Move the pivot to the correct place,
5. Repeat the same algorithm for the left partition and the right partition.

#### Complexity

$$
\begin{align*}
T(N) &= T\left(\tfrac{N}{10}\right) + T\left(9 \cdot \tfrac{N}{10}\right) + \mathcal{O}(N) \\
T(N) &= \mathcal{O}(N \cdot \log N)
\end{align*}
$$

```c++
void quickSort(int *ar, int size) {
    if (size <= 1) // base case
        return;

    int position = 1; // find the correct place of pivot
    swap(ar[0], ar[rand() % size]);

    for (int i = 1; i < size; i++)
        if (ar[0] > ar[i])
            swap(ar[i], ar[position++]);
    swap(ar[0], ar[position - 1]);

    quickSort(ar, position - 1);
    quickSort(ar + position, size - position);
}
```

### Radix Sort

*Quick Sort* and *Merge Sort* are comparison-based sorting algorithms and cannot run better than $\mathcal{O}(N \log N)$. However, *Radix Sort* works in linear time ($\mathcal{O}(N + K)$, where $K$ is $\log(\max(ar))$).

#### Procedure

1. For each digit from the least significant to the most, sort the array using *Counting Sort* according to corresponding digit. *Counting Sort* is used for keys between specific range, and it counts the number of elements which have different key values. After counting the number of distict key values, we can determine the position of elements in the array. 

#### Complexity

$$
\begin{align*}
T(N) &= \mathcal{O}(N)
\end{align*}
$$

```c++
void radixSort(int *ar, int size, int base = 10) {
    int *temp = new int[size];
    int *count = new int[base]();

    // Find the maximum value.
    int maxx = ar[0];
    for (int i = 1; i < size; i++) {
        if (ar[i] > maxx) {
            maxx = ar[i];
        }
    }

    for (int e = 1; maxx / e > 0; e *= base) {
        memset(count, 0, sizeof(int) * base);

        for (int i = 0; i < size; i++)
            count[(ar[i] / e) % base]++;

        for (int i = 1; i < base; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; 0 <= i; i--)
            temp[--count[(ar[i] / e) % base]] = ar[i];

        for (int i = 0; i < size; i++)
            ar[i] = temp[i];
    }

    delete[] temp;
    delete[] count;
}
```


## Quickselect Algorithm

*Quickselect* is a selection algorithm that *finds the $k^{th}$ smallest element in an unordered list*. The algorithm is closely related to QuickSort in partitioning stage; however, instead of recurring for both sides, it recurs only for the part that contains the $k^{th}$ smallest element.

#### Procedure

1. Choose a pivot randomly,
2. For all values in the array, collect smaller values in the left of the array and greater values in the right of the array,
3. Move the pivot to the correct place,
4. If the current position is equal to $k$, return the value at the position.
5. If the current position is more than $k$, repeat the same algorithm for the left partition.
6. Else, update $k$ and repeat the same algorithm for the right partition.

#### Complexity

- In average: $\mathcal{O}(N)$
- Worst-case: $\mathcal{O}(N^2)$

> Note that this algorithm is fast in practice, but has poor worst-case performance, like quicksort. However, it still performs better on average than other algorithms that find the $k^{th}$ smallest element in $\mathcal{O}(n)$ in the worst case.

```c++
// This function finds the k-th smallest element in arr within size si.
int QuickSelect(int *arr, int si, int k) {
    // Check if k is valid and if arr has no less elements than k.
    if (0 < k && k <= si) {
        // The quicksort-like partitioning. It is same until we find the index of the pivot.
        int ind = 0;

        // Get a random pivot to decrease the chance of getting worst-case scenario.
        swap(arr[si - 1], arr[rand() % si]);
        for (int j = 0; j < si - 1; j++) {
            if (arr[j] <= arr[si - 1]) {
                swap(arr[j], arr[ind]);
                ind++;
            }
        }
        swap(arr[si - 1], arr[ind]);

        // Now check and recur to appropriate situation.
        // If the index is equal with k-1 (as our array is 0-indexed) return the value.
        if (ind == k - 1) {
            return arr[ind];
        }
        // Else check if index is greater than k-1. If it is, recur to the left part.
        else if (ind > k - 1) {
            return QuickSelect(arr, ind, k);
        }
        // Else, recur to the right part.
        else {
            return QuickSelect(arr + ind + 1, si - ind - 1, k - ind - 1);
        }
    }
    // If invalid values is given
    return INT_MAX;
}
```

## Divide and Conquer

*Divide and Conquer* is a well-known paradigm that **breaks** up the problem into several parts, **solves** each part independently, and finally **combines** the solutions to the subproblems into the overall solution. Because each subproblem is solved recursively, they should be the smaller versions of the original problem; and the problem must have a base case to end the recursion. 

Some example algorithms that use divide and conquer technique: 

- Merge Sort
- Count Inversions
- Finding the Closest Pair of Points 
- [Others](https://www.geeksforgeeks.org/divide-and-conquer){target="_blank"}

<figure markdown="span" style="width: 55%">
![The Flow of *Divide and Conquer*](img/divide_and_conquer.png)
<figcaption>The Flow of Divide and Conquer</figcaption>
</figure>