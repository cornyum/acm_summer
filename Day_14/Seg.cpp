#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 1e5 + 10;
inline int lc(int x)  {return x << 1;}
inline int rc(int x)  {return x << 1 | 1;}
struct seg {
    int l, r;
    ll tag;
    ll sum, min, max;
    void update(ll value) {
        sum = value * (r - l + 1);
        min += value;
        max += value;
        tag += value;
    }
}tree[maxn << 2];
ll a[maxn];
void push_up(int p) {
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
    tree[p].max = max(tree[lc(p)].max, tree[rc(p)].max);
    tree[p].min = min(tree[lc(p)].min, tree[rc(p)].min);
}

void push_down(int p) {
    if (tree[p].tag) {
        tree[lc(p)].update(tree[p].tag);
        tree[rc(p)].update(tree[p].tag);
        tree[p].tag = 0;
    }
}

void bulid(int p, int l, int r) {
    if (l == r) {
        tree[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
    push_up(p);
}

void update(int p, int l, int r, ll v) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].update(v);
        return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l >= mid)
        update(lc(p), l, r, v);
    if (r < mid)
        update(rc(p), l, r, v);
    push_up(p);
}

ll querysum(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    push_down(p);
    ll ans = 0;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l >= mid)
        ans += querysum(lc(p), l, r);
    if (r < mid)
        ans += querysum(rc(p), l, r);
    return ans;
}

int main(void) {
    FAST_IO;

    pause;
    return 0;
}