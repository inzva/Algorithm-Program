---
title: Digit DP
tags:
    - Dynamic Programming
    - Digit DP
---

Problems that require the calculation of how many numbers there are between two values (say, \( A \) and \( B \)) that satisfy a particular property can be solved using digit dynamic programming (Digit DP).

---

## How to Work on Digits

While constructing our numbers recursively (from the left), we need a method to check if our number is still smaller than the given boundary number. To achieve this, we keep a variable called "strict" while branching, which limits our ability to select digits that are larger than the corresponding digit of the boundary number.

Let’s suppose the boundary number is \( A \). We start filling the number from the left (most significant digit) and set `strict` to `true`, meaning we cannot select any digit larger than the corresponding digit of \( A \). As we branch:

- Values less than the corresponding digit of \( A \) will now be non-strict (`strict = false`) because we guarantee that the number will be smaller than \( A \) after this point.
- For values equal to the corresponding digit of \( A \), the strictness continues to be `true`.

---

## Counting Problem Example

**Problem:** How many numbers \( x \) are there in the range \( A \) to \( B \), where the digit \( d \) occurs exactly \( k \) times in \( x \)?

**Constraints:** \( A, B < 10^{60}, k < 60 \).

### Brute Force Approach:

The brute-force solution would involve iterating over all the numbers in the range \([A, B]\) and counting the occurrences of the digit \( d \) one by one for each number. This has a time complexity of \( O(N \log_{10}(N)) \), which is too large for such constraints, and we need a more efficient approach.

### Recursive Approach:

We can recursively fill the digits of our number starting from the leftmost digit. At each step, we branch into 3 possibilities:

1. Pick a number that is **not** \( d \) and smaller than the corresponding digit of the boundary number.
2. Pick the digit \( d \).
3. Pick a number that is equal to the corresponding digit of the boundary number.

The depth of recursion is equal to the number of digits in the decimal representation of the boundary number, leading to a time complexity of \( O(3^{\log_{10} N}) \). Although this is better than brute force, it is still not efficient enough.

### Recursive Approach with Memoization:

We can further optimize this approach using memoization. We represent a DP state by \((\text{current index}, \text{current strictness}, \text{number of } d's)\), which denotes the number of possible configurations of the remaining digits after picking the current digit. We use a `dp[\log_{10} N][2][\log_{10} N]` array, where each value is computed at most once. Therefore, the worst-case time complexity is \( O((\log_{10} N)^2) \).

Solution Code:

```cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll A, B, d, k, dg; // dg: digit count
vector <ll> v; // digit vector
ll dp[25][2][25];
void setup(ll a)
{
    memset(dp,0,sizeof dp);
    v.clear();
    ll tmp = a;
    while(tmp)
    {
        v.push_back(tmp%10);
        tmp/=10;
    }
    dg = (ll)v.size();
    reverse(v.begin(), v.end());
}

ll rec(int idx, bool strict, int count)
{
    if(dp[idx][strict][count]) return dp[idx][strict][count];
    if(idx == dg or count > k) return (count == k);
    ll sum = 0;
    if(strict)
    {
        // all <v[idx] if d is included -1
        sum += rec(idx + 1, 0, count) * (v[idx] - (d < v[idx]));
        // v[idx], if d==v[idx] send count+1
        sum += rec(idx + 1, 1, count + (v[idx] == d) );
        if(d < v[idx])
        sum += rec(idx + 1, 0, count + 1); // d
    }
    else
    {
        sum += rec(idx + 1, 0, count) * (9); // other than d (10 - 1)
        sum += rec(idx + 1, 0, count + 1); // d
    }
    return dp[idx][strict][count] = sum;
}

int main()
{
    cin >> A >> B >> d >> k;
    setup(B);
    ll countB = rec(0, 1, 0); //countB is answer of [0..B]
    setup(A - 1);
    ll countA = rec(0, 1, 0); //countA is answer of [0..A-1]
    cout << fixed << countB - countA << endl; //difference gives us [A..B]
}
```

---

## References

- [Digit DP on Codeforces](https://codeforces.com/blog/entry/53960)

- [Digit DP on HackerRank](https://www.hackerrank.com/topics/digit-dp)