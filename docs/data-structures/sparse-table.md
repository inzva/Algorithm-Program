---
title: Sparse Table
tags:
    - Data Structures
    - Sparse Table
---

Sparse table aralıklardaki elemanların toplamı, minimumu, maksimumu ve EBOB'ları gibi sorgulara $\mathcal{O}(\log N)$ zaman karmaşıklığında cevap alabilmemizi sağlayan bir veri yapısıdır. Bazı tip sorgular (aralıktaki minimum, maksimum sayıyı bulma gibi) ise $\mathcal{O}(1)$ zaman karmaşıklığında yapmaya uygundur.

Bu veri yapısı durumu değişmeyen, sabit bir veri üzerinde ön işlemler yaparak kurulur. Dinamik veriler için kullanışlı değildir. Veri üzerinde herhangi bir değişiklik durumda Sparse table tekrardan kurulmalıdır. Bu da maliyetli bir durumdur.

## Yapısı ve Kuruluşu

Sparse table iki bouyutlu bir dizi şeklinde, $\mathcal{O}(N\log N)$ hafıza karmaşıklığına sahip bir veri yapısıdır. Dizinin her elemanından $2$'nin kuvvetleri uzaklıktaki elemanlara kadar olan cevaplar Sparse table'da saklanır. $ST_{x,i}$, $x$ indeksli elemandan $x + 2^i - 1$ indeksli elemana kadar olan aralığın cevabını saklayacak şekilde sparse table kurulur.

```c++
// Toplam sorgusu icin kurulmus Sparse Table Yapisi
const int n;
const int LOG = log2(n);
int a[n + 1], ST[2 * n][LOG + 1];

void build() {
    for (int i = 1; i <= n; i++) {
        // [i,i] araliginin cevabi dizinin i indeksli elemanina esittir.
        ST[i][0] = a[i];
    }

    for (int i = 1; i <= LOG; i++)
        for (int j = 1; j <= n; j++) {
            // [i,i+2^(j)-1] araliginin cevabi
            // [i,i+2^(j - 1) - 1] araligi ile [i+2^(j - 1),i+2^j-1] araliginin
            // cevaplarinin birlesmesiyle elde edilir
            ST[i][j] = ST[i][j - 1] + ST[i + (1 << (j - 1))][j - 1];
        }

    return;
}
```

## Sorgu Algoritması

Herhangi bir $[l,r]$ aralığı için sorgu algoritması sırasıyla şu şekilde çalışır:

- $[l,r]$ aralığını cevaplarını önceden hesapladığımız aralıklara parçala.
    - Sadece $2$'nin kuvveti uzunluğunda parçaların cevaplarını sakladığımız için aralığımızı $2$'nin kuvveti uzunluğunda aralıklara ayırmalıyız. $[l,r]$ aralığının uzunluğunun ikilik tabanda yazdığımızda hangi aralıklara parçalamamız gerektiğini bulmuş oluruz.
- Bu aralıklardan gelen cevapları birleştirerek $[l,r]$ aralığının cevabını hesapla.

Herhangi bir aralığın uzunluğunun ikilik tabandaki yazılışındaki $1$ rakamlarının sayısı en fazla $\log(N)$ olabileceğinden parçalayacağımız aralık sayısı da en fazla $\log(N)$ olur. Dolayısıyla sorgu işlemimiz $\mathcal{O}(\log N)$ zaman karmaşıklığında çalışır.

Örneğin: $[4,17]$ aralığının cevabını hesaplamak için algoritmamız $[4,17]$ aralığını $[4,11]$, $[12,15]$ ve $[16,17]$ aralıklarına ayırır ve bu $3$ aralıktan gelen cevapları birleştirerek istenilen cevabı hesaplar.

```c++
// toplam sorgusu
int query(int l, int r) {
    int res = 0;

    for (int i = LOG; i >= 0; i--) {
        // her seferinde uzunlugu r - l + 1 gecmeyecek
        // en buyuk araligin cevabi ekleyip l'i o araligin sonuna cekiyoruz.
        if (l + (1 << i) <= r) {
            res += ST[l][i];
            l += (1 << i);
        }
    }

    return res;
}
```

## Minimum ve Maksimum Sorgu

Sparse Table veri yapısının diğer veri yapılarından farklı olarak $\mathcal{O}(1)$ zaman karmaşıklığında aralıklarda minimum veya maksimum sorgusu yapabilmesi en avantajlı özelliğidir.

Herhangi bir aralığın cevabını hesaplarken bu aralıktaki herhangi bir elemanı birden fazla kez değerlendirmemiz cevabı etkilemez. Bu durum aralığımızı $2$'nin kuvveti uzunluğunda maksimum $2$ adet aralığa bölebilmemize ve bu aralıkların cevaplarını $\mathcal{O}(1)$ zaman karmaşıklığında birleştirebilmemize olanak sağlar.

```c++
int RMQ(int l, int r) {
    // log[] dizisinde her sayinin onceden hesapadigimiz log2 degerleri saklidir.
    int j = log[r - l + 1];
    return min(ST[l][j], ST[r - (1 << j) + 1][j]);
}
```

Sparse Table veri yapısı ile ilgili örnek bir probleme [buradan](https://www.spoj.com/problems/RMQSQ){target="_blank"} ulaşabilirsiniz.
