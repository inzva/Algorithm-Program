---
title: Deque
tags:
    - Data Structures
    - Deque
---

Deque veri yapısı stack ve queue veri yapılarına göre daha kapsamlıdır. Bu veri yapısında yapının en üstüne eleman eklenebilirken aynı zamanda en altına da eklenebilir. Aynı şekilde yapının hem en üstündeki elemanına hem de en alttaki elemanına erişim ve silme işlemleri uygulanabilir. Bu veri yapısında uyguluyabildiğimiz işlemler:

- Veri yapısının en üstüne eleman ekleme.
- Veri yapısının en altına eleman ekleme.
- Veri yapısının en üstündeki elemanına erişim.
- Veri yapısının en altındaki elemanına erişim.
- Veri yapısının en üstündeki elemanı silme.
- Veri yapısının en altındaki elemanı silme.

C++ dilindeki STL kütüphanesinde bulunan hazır deque yapısının kullanımı aşağıdaki gibidir:

```c++
int main() {
    deque<int> q;
    q.push_front(5);   // deque'nin en altina 5'i ekler.
    q.push_back(6);    // deque'nin en ustune 6'yi ekler.
    int x = q.front(); // deque'nin en altindaki elemanina erisim.
    int y = q.back();  // deque'nin en ustundeki elemanina erisim.
    q.pop_front();     // deque'nin en altindaki elemanini silme.
    q.pop_back();      // deque'nin en ustundeki elemanini silme.
}
```

**P.S.** deque veri yapısı stack ve queue veri yapılarına göre daha kapsamlı olduğundan ötürü stack ve queue veri yapılarına göre 2 kat fazla memory kullandığını açıklıkla söyleyebiliriz.
