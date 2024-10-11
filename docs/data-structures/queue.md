---
title: Queue
tags:
    - Data Structures
    - Queue
---

Queue veri yapısında elemanlar yapıya ilk giren ilk çıkar (FIFO) kuralına uygun olacak şekilde saklanır. Bu veri yapısında uygulayabildigimiz işlemler:

- Veri yapısının en üstüne eleman ekleme.
- Veri yapısının en altındaki elemanına erişim.
- Veri yapısının en altındaki elemanı silme.
- Veri yapısının boş olup olmadığının kontrölü.

C++ dilindeki STL kütüphanesinde bulunan hazır queue yapısının kullanımı aşağıdaki gibidir:

```c++
int main() {
    queue<int> q;
    cout << q.empty() << endl; // Ilk bashta Queue bosh oldugu icin burada True donecektir.
    q.push(5);                 // Queue'in en ustune 5'i ekler. Queue'in yeni hali: {5}
    q.push(7);                 // Queue'in en ustune 7'yi ekler. Queue'in yeni hali: {7, 5}
    q.push(6);                 // Queue'in en ustune 6'yi ekler. Queue'in yeni hali : {6, 7, 5}
    q.pop();                   // Queue'in en altindaki elemani siler. Queue'in yeni hali : {6, 7}
    q.push(1);                 // Queue'in en ustune 1'i ekler. Queue'in yeni hali : {1, 6, 7}
    cout << Q.front() << endl; // Queue'in en ustundeki elemana erisir. Ekrana 7 yazdirir.
}
```