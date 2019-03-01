#include<bits/stdc++.h>
using namespace std;

struct Treap{
    int val, prior, cnt;
    Treap *l, *r;
    Treap(int v): l(NULL), r(NULL), val(v), prior((rand() << 15) + rand()), cnt(1) {}
} *root;

int sz(Treap *t) {return (t == NULL) ? 0:t->cnt;}

void upd_sz(Treap *t){
    if(t) t->cnt = 1 + sz(t->l) + sz(t->r);
}

void split(Treap *t, Treap *&l, Treap *&r, int pos, int add = 0)
{
    if(!t) return void(l = r = NULL);
    int cur_pos = add + sz(t->l) + 1;
    if(cur_pos <= pos) split(t->r, t->r, r, pos, cur_pos), l = t;
    else split(t->l, l ,t->l, pos, add), r = t;
    upd_sz(t);
}

void merge(Treap *&t, Treap *l, Treap *r)
{
    if(!l || !r) t = l? l:r;
    else if(l->prior > r->prior) {merge(l->r, l->r, r); t = l;}
    else {merge(r->l, l, r->l);t = r;}
    upd_sz(t);
}

void insert(Treap *&t, int pos, int val)
{
    Treap *l, *r, *cur = new Treap(val);
    split(t, l, r, pos-1);
    merge(t, l, cur);
    merge(t, t, r);
}

void erase(Treap *&t, int pos)
{
    Treap *l, *r, *g;
    split(t, l, r, pos-1);
    split(r, g, r, 1);
    merge(t, l, r);
}

int find_kth(Treap *t, int k, int add = 0)
{
    assert(t);
    int cur_pos = add + sz(t->l) + 1;
    if(cur_pos == k) return t-> val;
    if(cur_pos < k) return find_kth(t->r, k, cur_pos);
    return find_kth(t->l, k, add);
}


int main()
{
    //freopen("in.txt", "r", stdin);
    int i, j, k, n, m, v;
    int type, l, r;
    Treap *leftPart, *rightPart, *middlePart;

    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++)
    {
        scanf("%d", &v);
        insert(root, i, v);
    }

    for(i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &type, &l, &r);

        split(root, leftPart, rightPart, l-1);
        split(rightPart, middlePart, rightPart, r-l+1);

        if(type == 1)
        {
            merge(root, middlePart, leftPart);
            merge(root, root, rightPart);
        }
        else
        {
            merge(root, leftPart, rightPart);
            merge(root, root, middlePart);
        }
    }

    printf("%d\n", abs(find_kth(root, 1) - find_kth(root, n)));
    for(i = 1; i <= n; i++)
        printf("%d ", find_kth(root, i));

    return 0;
}