#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int Random() { return rand() << 15 | rand(); }

typedef struct item * pitem;

struct item {
    int prior;
    bool rev;
    pitem l, r;
    int cnt;
    char val;
    item(char val = '?'): val(val), l(NULL), r(NULL), rev(false), cnt(1), prior(Random()) { }
};

const int Maxl = 100005;

int n, l, r;
char s[Maxl];
pitem trie;

int cnt (pitem it) {
    return it ? it->cnt : 0;
}

void upd_cnt (pitem it) {
    if (it)
        it->cnt = cnt(it->l) + cnt(it->r) + 1;
}

void push (pitem it) {
    if (it && it->rev) {
        it->rev = false;
        swap (it->l, it->r);
        if (it->l)  it->l->rev ^= true;
        if (it->r)  it->r->rev ^= true;
    }
}

void merge (pitem & t, pitem l, pitem r) {
    push (l);
    push (r);
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt (t);
}

void split (pitem t, pitem & l, pitem & r, int key, int add = 0) {
    if (!t)
        return void( l = r = 0 );
    push (t);
    int cur_key = add + cnt(t->l);
    if (key <= cur_key)
        split (t->l, l, t->l, key, add),  r = t;
    else
        split (t->r, t->r, r, key, add + 1 + cnt(t->l)),  l = t;
    upd_cnt (t);
}

void reverse (pitem t, int l, int r) {
    pitem t1, t2, t3;
    split (t, t1, t2, l);
    split (t2, t2, t3, r-l+1);
    t2->rev ^= true;
    merge (t, t1, t2);
    merge (t, t, t3);
}

char get(pitem t, int key, int add = 0)
{
    push(t);
    int cur_key = add + cnt(t->l);
    if (key < cur_key) return get(t->l, key, add);
    else if (key == cur_key) return t->val;
    else return get(t->r, key, add + 1 + cnt(t->l));
}

int main()
{
    scanf("%d %d %d", &n, &l, &r); l--; r--;
    scanf("%s", s);
    trie = new item(s[0]);
    for (int i = 1; i < n; i++)
        merge(trie, trie, new item(s[i]));
    int m; scanf("%d", &m);
    while (m--) {
        char a, b, c; scanf(" %c", &a);
        if (a == 'S') {
            scanf(" %c %c", &b, &c);
            if (b == 'L') if (c == 'L') l--;
                          else l++;
            else if (c == 'L') r--;
                 else r++;
        } else if (a == 'R') reverse(trie, l, r);
          else {
                  scanf(" %c", &b);
                  if (b == 'L') printf("%c", get(trie, l));
                  else printf("%c", get(trie, r));
          }
    }
    printf("\n");
    return 0;
}