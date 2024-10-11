---
title: Fenwick Tree
tags:
    - Data Structures
    - Fenwick Tree
    - Binary Indexed Tree
    - BIT
---

Binary Indexed Tree olarak da bilinen Fenwick Tree, [Prefix Sum](prefix-sum.md) ve [Sparse Table](sparse-table.md) yapılarına benzer bir yapıda olup dizi üzerinde değişiklik yapabilmemize olanak sağlayan bir veri yapısıdır. Fenwick Tree'nin diğer veri yapılarına göre en büyük avantajı pratikte daha hızlı olması ve hafıza karmaşıklığının $\mathcal{O}(N)$ olmasıdır. Ancak Fenwick Tree'de sadece prefix cevapları (veya suffix cevapları) saklayabildiğimizden aralıklarda minimum, maksimum ve EBOB gibi bazı sorguların cevaplarını elde edemeyiz.

## Yapısı ve Kuruluşu

$g(x)$, $x$ sayısının bit gösteriminde yalnızca en sağdaki bitin 1 olduğu tam sayı olsun. Örneğin $20$'nin bit gösterimi $(10100)_2$ olduğundan $g(20)=4$'tür. Çünkü ilk kez sağdan $3.$ bit $1$'dir ve $(00100)_2=4$'tür. Fenwick Tree'nin $x$ indeksli düğümünde, <span style="white-space: nowrap">$x - g(x) + 1$</span> indeksli elemandan $x$ indeksli elemana kadar olan aralığın cevabını saklayacak şekilde kurulur.

<figure markdown="span">
![8 uzunluğundaki bir dizi için kurulmuş Fenwick Tree yapısı](img/fenwick.png){ width="80%" }
<figcaption>$8$ uzunluğundaki bir dizi için kurulmuş Fenwick Tree yapısı</figcaption>
</figure>


## Sorgu Algoritması

Herhangi bir $[1,x]$ aralığı için sorgu algoritması sırası ile şu şeklide çalışır:

1. Aradığımız cevaba $[x - g(x) + 1,x]$ aralığının cevabını ekle.
2. $x$'in değerini $x - g(x)$ yap. Eğer $x$'in yeni değeri $0$'dan büyük ise $1.$ işlemden hesaplamaya devam et.

$[1,x]$ aralığının cevabını hesaplamak için yapılan işlem sayısı $x$ sayısının $2$'lik tabandaki yazılışındaki $1$ sayısına eşittir. Çünkü her döngüde $x$'ten $2$'lik tabandaki yazılışındaki en sağdaki $1$ bitini çıkartıyoruz. Dolayısıyla sorgu işlemimiz $\mathcal{O}(\log N)$ zaman karmaşıklığında çalışır. $[l,r]$ aralığının cevabını da $[1,r]$ aralığının cevabından $[1,l - 1]$ aralığının cevabını çıkararak kolay bir şekilde elde edebiliriz.

> NOT: $g(x)$ değerini bitwise operatörlerini kullanarak aşağıdaki eşitlikle kolay bir şekilde hesaplayabiliriz:
>  \\[g(x) = x \ \& \ (-x)\\]

## Eleman Güncelleme Algoritması

Dizideki $x$ indeksli elemanının değerini güncellemek için kullanılan algoritma şu şeklide çalışır:

- Ağaçta $x$ indeksli elemanı içeren tüm düğümlerin değerlerini güncelle.

Fenwick Tree'de $x$ indeksli elemanı içeren maksimum $\log(N)$ tane aralık olduğundan güncelleme algoritması $\mathcal{O}(\log N)$ zaman karmaşıklığında çalışır.

## Örnek Kod Parçaları

```c++
const int n;
int tree[n + 1], a[n + 1];

void add(int val, int x) { // x indeksli elemanin degerini val degeri kadar artirir.
    // x indeksinin etkiledigi butun dugumleri val degeri kadar artirir.
    while (x <= n) {
        tree[x] += val;
        x += x & (-x);
    }
}

int sum(int x) { // 1 indeksli elemandan x indeksli elemana
    int res = 0; // kadar olan sayilarin toplamini verir.
    while (x >= 1) {
        res += tree[x];
        x -= x & (-x);
    }
    return res;
}

int query(int l, int r) { // [l,r] araligindaki elemanlarin toplamini verir.
    return sum(r) - sum(l - 1);
}

void build() { // a dizisi uzerine fenwick tree yapisini kuruyoruz.
    for (int i = 1; i <= n; i++)
        add(a[i], i);
}
```

Fenwick Tree veri yapısı ile ilgili örnek bir probleme [buradan](https://www.spoj.com/problems/CSUMQ) ulaşabilirsiniz.

## Aralık Güncelleme ve Eleman Sorgu

Bir $a$ dizisi üzerinde işlemler yapacağımızı varsayalım daha sonra $a$ dizisi $b$ dizisinin prefix sum dizisi olacak şekilde bir $b$ dizisi tanımlayalım. Başka bir deyişle $a_i = \displaystyle\sum_{j=1}^{i} {b_j} $ olmalıdır. Sonradan oluşturduğumuz $b$ dizisi üzerine Fenwick Tree yapısını kuralım. $[l,r]$ aralığındaki her elemana
$x$ değerini eklememiz için uygulamamız gereken işlemler:

- $b_l$ değerini $x$ kadar artır. Böylelikle $l$ indeksli elemandan dizinin sonuna kadar tüm elemanların değeri $x$ kadar artmış olur.
- $b_{r + 1}$ değerini $x$ kadar azalt. Böylelikle $r + 1$ indeksli elemandan dizinin sonuna kadar tüm elemanların değeri $x$ kadar azalmış olur. Bu işlemelerin sonucunda sadece $[l,r]$ aralığındaki elemanların değeri $x$ kadar artmış olur.

### Örnek Kod Parçaları

```c++
const int n;
int a[n + 1], b[n + 1];

void add(int val, int x) { // x indeksli elemanin degerini val degeri kadar artirir.
    while (x <= n) {
        tree[x] += val;
        x += x & (-x);
    }
}

int sum(int x) { // 1 indeksli elemandan x indeksli elemana
    int res = 0; // kadar olan sayilarin toplamini verir.
    while (x >= 1) {
        res += tree[x];
        x -= x & (-x);
    }
    return res;
}
void build() {
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1]; // b dizisini olusturuyoruz.

    for (int i = 1; i <= n; i++)
        add(b[i], i); // b dizisi uzerine fenwick tree kuruyoruz.
}

void update(int l, int r, int x) {
    add(x, l);
    add(-x, r + 1);
}

void query(int x) { return sum(x); }
```
