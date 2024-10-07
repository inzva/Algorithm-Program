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