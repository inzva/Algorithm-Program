---
title: Segment Tree
tags:
    - Data Structures
    - Segment Tree
---

Segment Tree bir dizide $\mathcal{O}(\log N)$ zaman karmaşıklığında herhangi bir $[l,r]$ aralığı icin minimum, maksimum, toplam gibi sorgulara cevap verebilmemize ve bu aralıklar üzerinde güncelleme yapabilmemize olanak sağlayan bir veri yapısıdır.

Segment Tree, [Fenwick Tree](fenwick-tree.md) ve [Sparse Table](sparse-table.md) yapılarından farklı olarak elemanlar üzerinde güncelleme yapılabilmesi ve minimum, maksimum gibi sorgulara da olanak sağlaması yönünden daha kullanışlıdır. Ayrıca Segment Tree $\mathcal{O}(N)$ hafıza karmaşıklığına sahipken Sparse Table yapısında gereken hafıza karmaşıklığı $\mathcal{O}(N \log N)$'dir.

## Yapısı ve Kuruluşu
Segment Tree, "Complete Binary Tree" yapısına sahiptir. Segment Tree'nin yaprak düğümlerinde dizinin elemanları saklıdır ve bu düğümlerin atası olan her düğüm kendi çocuğu olan düğümlerinin cevaplarının birleşmesiyle oluşur. Bu sayede her düğümde belirli aralıkların cevapları ve root düğümünde tüm dizinin cevabı saklanır. Örneğin toplam sorgusu için kurulmuş bir Segment Tree yapısı için her düğümün değeri çocuklarının değerleri toplamına eşittir.

<figure markdown="span">
![a = [41,67,6,30,85,43,39] dizisinde toplam sorgusu icin oluşturulmuş Segment Tree yapısı](img/segtree.png){ width="100%" }
<figcaption>$a = [41,67,6,30,85,43,39]$ dizisinde toplam sorgusu icin oluşturulmuş Segment Tree yapısı</figcaption>
</figure>

```c++
void build(int ind, int l, int r) {
    // tree[ind] dizinin [l,r] araliginin cevabini saklar.
    if (l == r) {         // yaprak dugum'e ulasti
        tree[ind] = a[l]; // bu dugum dizinin l. elamaninin cevabini saklar
    } else {
        int mid = (l + r) / 2;
        build(ind * 2, l, mid);
        build(ind * 2 + 1, mid + 1, r);
        // [l,r] araliginin cevabini
        // [l,mid] ve [mid + 1,r] araliklarinin cevaplarinin birlesmesiyle olusur.
        tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
    }
}
```

## Aralık Sorgu ve Eleman Güncelleme

### Sorgu Algoritması

Herhangi bir $[l,r]$ aralığı için sorgu algoritması sırası ile şu şekilde çalışır:
- $[l,r]$ aralığını ağacımızda cevapları saklı olan en geniş aralıklara parçala.
- Bu aralıkların cevaplarını birleştirerek istenilen cevabı hesapla.

Ağacın her derinliğinde cevabımız için gerekli aralıklardan maksimum $2$ adet bulunabilir. Bu yüzden sorgu algoritması $\mathcal{O}(\log N)$ zaman karmaşıklığında çalışır.

<figure markdown="span">
![a = [41,67,6,30,85,43,39] dizisinde $[2,6]$ aralığında sorgu işlemi](img/segtreequery.png){ width="100%" }
<figcaption>$a = [41,67,6,30,85,43,39]$ dizisinde $[2,6]$ aralığında sorgu işlemi</figcaption>
</figure>

$a = [41,67,6,30,85,43,39]$ dizisinde $[2,6]$ aralığının cevabı $[2,3]$ ile $[4,6]$ aralıklarının cevaplarının birleşmesiyle elde edilir. Toplam sorgusu için cevap $36+167=203$ şeklinde hesaplanır.

```c++
// [lw,rw] sorguda cevabini aradigimiz aralik.
// [l,r] ise agactaki ind nolu node'da cevabini sakladigimiz aralik.
int query(int ind, int l, int r, int lw, int rw) {
    if (l > rw or r < lw) // bulundugumuz aralik cevabini aradigimiz araligin disinda.
        return 0;
    if (l >= lw and r <= rw) // cevabini aradigimiz aralik bu araligi tamamen kapsiyor.
        return tree[ind];

    int mid = (l + r) / 2;

    // Agacta recursive bir sekilde araligimizi araliklara bolup gelen cevaplari birlestiyoruz.
    return query(ind * 2, l, mid, lw, rw) + query(ind * 2 + 1, mid + 1, r, lw, rw);
}
```

### Eleman Güncelleme Algoritması

Dizideki $x$ indeksli elemanının değerini güncellemek için kullanılan algoritma şu şeklide çalışır:

- Ağaçta $x$ indeksli elemanı içeren tüm düğümlerin değerlerini güncelle.

Ağaçta $x$ indeksli elemanın cevabını tutan yaprak düğümden root düğüme kadar toplamda $\log(N)$ düğümün değerini güncellememiz yeterlidir. Dolayısıyla herhangi bir elemanın değerini güncellemenin zaman karmaşıklığı $\mathcal{O}(\log N)$'dir.

<figure markdown="span">
![a = [41,67,6,30,85,43,39] dizisinde 5 indeksli elemanın cevabını güncellerken güncellememiz gereken düğümler şekildeki gibidir.](img/segtreeupdate.png){ width="100%" }
<figcaption>$a = [41,67,6,30,85,43,39]$ dizisinde 5 indeksli elemanın cevabını güncellerken güncellememiz gereken düğümler sekildeki gibidir.</figcaption>
</figure>

```c++
void update(int ind, int l, int r, int x, int val) {
    if (l > x || r < x) // bulundugumuz aralik x indeksli elemani icermiyor.
        return;
    if (l == x and r == x) {
        tree[ind] = val; // x indeksli elemani iceren yaprak dugumunun cevabini guncelliyoruz.
        return;
    }

    int mid = (l + r) / 2;

    // recursive bir sekilde x indeksli elemani iceren
    // tum araliklarin cevaplarini guncelliyoruz.
    update(ind * 2, l, mid, x, val);
    update(ind * 2 + 1, mid + 1, r, x, val);
    tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
}
```

Segment Tree veri yapısı ile ilgili örnek bir probleme [buradan](https://codeforces.com/gym/100739/problem/A){target="_blank"} ulaşabilirsiniz.
