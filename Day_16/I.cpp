#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1e5 + 10;
inline int lc(int x) { return x << 1; }
inline int rc(int x) { return x << 1 | 1; }
struct seg {
    int l, r, mid;
    ll sum, tag;
    void update(ll x) {
        sum += x * (r - l + 1);
        tag += x;
    }
}tree[maxn];
int a[maxn];

void push_up(int p) {
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
}

void push_down(int p) {
    if (tree[p].tag) {
        tree[lc(p)].update(tree[p].tag);
        tree[rc(p)].update(tree[p].tag);
        tree[p].tag = 0;
    }
}

void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r;
    int mid = (l + r) >> 1;
    tree[p].mid = mid;
    tree[p].sum = tree[p].tag = 0;
    if (l == r) {
        tree[p].sum = a[l];
        return;
    }
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
}

void update(int p, int l, int r, ll v) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].update(v);
        return;
    }
    push_down(p);
    int mid = tree[p].mid;
    if (l <= mid)
        update(lc(p), l, r, v);
    if (r > mid)
        update(rc(p), l, r, v);
    push_up(p);
}

ll query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    ll ans = 0;
    int mid = tree[p].mid;
    if (l <= mid)
        ans += query(lc(p), l, r);
    if (r > mid)
        ans += query(rc(p), l, r);
    return ans;
}

int main(void) {


    return 0;
}