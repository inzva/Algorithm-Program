---
title: SQRT Decomposition
tags:
    - Data Structures
    - SQRT Decomposition
    - Square Root Decomposition
---

Square Root Decomposition algoritması dizi üzerinde $\mathcal{O}(\sqrt{N})$ zaman karmaşıklığında sorgu yapabilmemize ve $\mathcal{O}(1)$ zaman karmaşıklığında ise değişiklik yapabilmemize olanak sağlayan bir veri yapsıdır.

## Yapısı ve Kuruluşu

Dizinin elemanları her biri yaklaşık $\mathcal{O}(\sqrt{N})$ uzunluğunda bloklar halinde parçalanır. Her bir blokun cevabı ayrı ayrı hesaplanır ve bir dizide saklanır.

<div align="center" markdown="span">
    <table>
        <thead>
            <tr>
                <th>Blokların Cevapları</th>
                <th colspan="4" align="center">$21$</th>
                <th colspan="4" align="center">$13$</th>
                <th colspan="4" align="center">$50$</th>
                <th colspan="4" align="center">$32$</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>Dizideki Elemanlar</td>
                <td>$3$</td>
                <td>$6$</td>
                <td>$2$</td>
                <td>$10$</td>
                <td>$3$</td>
                <td>$1$</td>
                <td>$4$</td>
                <td>$5$</td>
                <td>$2$</td>
                <td>$7$</td>
                <td>$37$</td>
                <td>$4$</td>
                <td>$11$</td>
                <td>$6$</td>
                <td>$8$</td>
                <td>$7$</td>
            </tr>
            <tr>
                <td>Elemanların İndeksleri</td>
                <td>$1$</td>
                <td>$2$</td>
                <td>$3$</td>
                <td>$4$</td>
                <td>$5$</td>
                <td>$6$</td>
                <td>$7$</td>
                <td>$8$</td>
                <td>$9$</td>
                <td>$10$</td>
                <td>$11$</td>
                <td>$12$</td>
                <td>$13$</td>
                <td>$14$</td>
                <td>$15$</td>
                <td>$16$</td>
            </tr>
        </tbody>
    </table>

    *Örnek bir dizi üzerinde toplam sorgusu için kurulmuş SQRT Decompostion veri yapısı.*
</div>

```c++
void build() {
    for (int i = 1; i <= n; i++) {
        if (i % sq == 1) { // sq = sqrt(n)
            t++;           // yeni blok baslangici.
            st[t] = i;     // t.blok i indisli elemanda baslar.
        }
        fn[t] = i;      // t.blokun bitisini i indisli eleman olarak guncelliyoruz.
        wh[i] = t;      // i indeksli eleman t.blogun icinde.
        sum[t] += a[i]; // t. blokun cevabina i indeksli elemani ekliyoruz.
    }
}
```

## Sorgu Algoritması

Herhangi bir $[l,r]$ aralığı için sorgu algoritması sırası ile şu şekilde çalışır:

1. Cevabını aradığımız aralığın tamamen kapladığı blokların cevabını cevabımıza ekliyoruz.
2. Tamamen kaplamadığı bloklardaki aralığımızın içinde olan elemanları tek tek gezerek cevabımıza ekliyoruz.

Cevabını aradığımız aralığın kapsadığı blok sayısı en fazla $\sqrt{N}$ olabileceğinden $1.$ işlem en fazla $\sqrt{N}$ kez çalışır. Tamamen kaplamadığı ancak bazı elemanları içeren en fazla $2$ adet blok olabilir. (Biri en solda diğeri en sağda olacak şekilde.) Bu $2$ blok için de gezmemiz gereken eleman sayısı maksimum $2\sqrt{N}$ olduğundan bir sorgu işleminde en fazla $3\sqrt{N}$ işlem yapılır, dolayısıyla sorgu işlemimiz $\mathcal{O}(\sqrt{N})$ zaman karmaşıklığında calışır.

<div align="center" markdown="span">
    <table>
        <thead>
            <tr>
                <th>Blokların Cevapları</th>
                <th colspan="4" align="center">$21$</th>
                <th colspan="4" align="center" style="color: blue; background-color: turquoise">$13$</th>
                <th colspan="4" align="center" style="color: blue; background-color: turquoise">$50$</th>
                <th colspan="4" align="center">$32$</th>
            </tr>
        </thead>
        <tbody>
            <tr>
                <td>Dizideki Elemanlar</td>
                <td>$3$</td>
                <td>$6$</td>
                <td style="color: blue; background-color: turquoise">$2$</td>
                <td style="color: blue; background-color: turquoise">$10$</td>
                <td>$3$</td>
                <td>$1$</td>
                <td>$4$</td>
                <td>$5$</td>
                <td>$2$</td>
                <td>$7$</td>
                <td>$37$</td>
                <td>$4$</td>
                <td style="color: blue; background-color: turquoise">$11$</td>
                <td>$6$</td>
                <td>$8$</td>
                <td>$7$</td>
            </tr>
            <tr>
                <td>Elemanların İndeksleri</td>
                <td>$1$</td>
                <td>$2$</td>
                <td>$3$</td>
                <td>$4$</td>
                <td>$5$</td>
                <td>$6$</td>
                <td>$7$</td>
                <td>$8$</td>
                <td>$9$</td>
                <td>$10$</td>
                <td>$11$</td>
                <td>$12$</td>
                <td>$13$</td>
                <td>$14$</td>
                <td>$15$</td>
                <td>$16$</td>
            </tr>
        </tbody>
    </table>

    *Örnek dizideki $[3,13]$ aralığının cevabını $2.$ ve $3.$ blokların cevapları ile $3,4$ ve $11$ indeksli elemanların toplanmasıyla elde edilir.*
</div>

```c++
// [l,r] araligindaki elemanlarin toplamini hesaplayan fonksiyon.
int query(int l, int r) {
    int res = 0;

    if (wh[l] == wh[r]) { // l ve r ayni blogun icindeyse
        for (int i = l; i <= r; i++)
            res += a[i];
    } else {
        for (int i = wh[l] + 1; i <= wh[r] - 1; i++)
            res += sum[i]; // tamamen kapladigimiz bloklarin cevaplarini ekliyoruz.

        // tamamen kaplamadigimiz bloklardaki araligimiz icindeki
        // elemanlarin cevaplarini ekliyoruz.

        for (int i = st[wh[l]]; i <= fn[wh[l]]; i++)
            if (i >= l && i <= r)
                res += a[i];

        for (int i = st[wh[r]]; i <= fn[wh[r]]; i++)
            if (i >= l && i <= r)
                res += a[i];
    }

    return res;
}
```

## Eleman Güncelleme Algoritması

Herhangi bir elemanın değerini güncellerken o elemanı içeren blokun değerini güncellememiz yeterli olacaktır. Dolayısıyla güncelleme işlemimimiz $\mathcal{O}(1)$ zaman karmaşıklığında çalışır.

```c++
void update(int x, int val) {
    // x indeksli elemanin yeni degerini val degerine esitliyoruz.
    sum[wh[x]] -= a[x];
    a[x] = val;
    sum[wh[x]] += a[x];
}
```

SQRT Decomposition veri yapısı ile ilgili örnek bir probleme [buradan](https://codeforces.com/contest/13/problem/E){target="_blank"} ulaşabilirsiniz.
