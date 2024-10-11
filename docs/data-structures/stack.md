---
title: Stack
tags:
    - Data Structures
    - Stack
---

Stack veri yapısında elemanlar yapıya son giren ilk çıkar (LIFO) kuralına uygun olacak şekilde saklanır. Bu veri yapısında uygulayabildiğimiz işlemler:

- Veri yapısının en üstüne eleman ekleme.
- Veri yapısının en üstündeki elemana erişim.
- Veri yapısının en üstündeki elemanı silme.
- Veri yapısının boş olup olmadığının kontrölü.

C++ dilindeki STL kütüphanesinde bulunan hazır stack yapısının kullanımı aşağıdaki gibidir:

```c++
int main() {
    stack<int> st;
    cout << st.empty() << endl; // Ilk bashta Stack bosh oldugu icin burada True donecektir.
    st.push(5);                 // Stack'in en ustune 5'i ekler. Stack'in yeni hali: {5}
    st.push(7);                 // Stack'in en ustune 7'yi ekler. Stack'in yeni hali: {7, 5}
    st.push(6);                 // Stack'in en ustune 6'yi ekler. Stack'in yeni hali : {6, 7, 5}
    st.pop();                   // Stack'in en ustundeki elemani siler. Stack'in yeni hali : {7, 5}
    st.push(1);                 // Stack'in en ustune 1'i ekler. Stack'in yeni hali : {1, 7, 5}
    cout << st.top() << endl;   // Stack'in en ustundeki elemana erisir. Ekrana 1 yazirir.
    cout << st.empty() << endl; // Burada Stack bosh olmadigindan oturu False donecektir.
}
```