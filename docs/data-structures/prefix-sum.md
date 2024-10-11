---
title: Prefix Sum
tags:
    - Data Structures
    - Prefix Sum
---

Prefix Sum dizisi bir dizinin prefixlerinin toplamlarıyla oluşturulan bir veri yapısıdır. Prefix sum dizisinin $i$ indeksli elemanı girdi dizisindeki $1$ indeksli elemandan $i$ indeksli elemana kadar olan elemanların toplamına eşit olacak şekilde kurulur. Başka bir deyişle:

$$sum_i = \sum_{j=1}^{i} {a_j}$$

Örnek bir $A$ dizisi için prefix sum dizisi şu şekilde kurulmalıdır:

<div align="center" markdown="1">
| **A Dizisi**          | $4$ | $6$   | $3$     | $12$       | $1$          |
|-------------------:|:---:|:-----:|:-------:|:----------:|:------------:|
| **Prefix Sum Dizisi** | $4$ | $10$  | $13$    | $25$       | $26$         |
|                   | $4$ | $4+6$ | $4+6+3$ | $4+6+3+12$ | $4+6+3+12+1$ |
</div>

Prefix sum dizisini kullanarak herhangi bir $[l,r]$ aralığındaki elemanların toplamını şu şekilde kolaylıkla elde edebiliriz:

$$sum_r = \sum_{j=1}^{r} {a_j}$$

$$sum_{l - 1} = \sum_{j=1}^{l - 1} {a_j}$$

$$sum_r - sum_{l-1} = \sum_{j=l}^{r} {a_j}$$

## Örnek Kod Parçaları

Prefix Sum dizisini kurarken $sum_i = sum_{i - 1} + a_i$ eşitliği kolayca görülebilir ve bu eşitliği kullanarak $sum[]$ dizisini girdi dizisindeki elemanları sırayla gezerek kurabiliriz:

```c++
const int n;
int sum[n + 1], a[n + 1];
// a dizisi girdi dizimiz, sum dizisi de prefix sum dizimiz olsun.

void build() {
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    return;
}

int query(int l, int r) {
    return sum[r] - sum[l - 1];
}
```

## Zaman Karmaşıklığı

Prefix sum dizisini kurma işlemimizin zaman ve hafıza karmaşıklığı $\mathcal{O}(N)$. Her sorguya da $\mathcal{O}(1)$ karmaşıklıkta cevap verebiliyoruz.

Prefix sum veri yapısı ile ilgili örnek bir probleme [buradan](https://codeforces.com/problemset/problem/816/B){target="_blank"} ulaşabilirsiniz.
