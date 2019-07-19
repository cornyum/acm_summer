#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
#define scan scanf
#define print printf
#define pause system("pause")
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return x << 1 | 1;
}

int const maxn = 200000 + 10;
struct seg {
    int l, r;
    int max;
    void update(int v) {
        max = v;
    }
}tree[maxn << 2];
int a[maxn];

void push_up(int p) {
    tree[p].max = max(tree[lc(p)].max, tree[rc(p)].max);
}

void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].max = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
    push_up(p);
}

void update(int p, int x, int v) {
    if (tree[p].l == tree[p].r) {
        tree[p].update(v);
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (x <= mid)
        update(lc(p), x, v);
    else 
        update(rc(p), x, v);
    push_up(p);
}

int query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].max;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    int ans = -0x3f3f3f;
    if(l <= mid)
        ans = max(ans, query(lc(p), l, r));
    if (r > mid)
        ans = max(ans, query(rc(p), l, r));
    return ans;
}

int main(void) {
    FAST_IO;
    int n, m;
    while (scan("%d %d", &n, &m) != EOF) {
        for (int i = 1; i <= n; i++) {
            // cin >> a[i];
            scan("%d", &a[i]);
        }
        bulid(1, 1, n);
        char opt[10];
        int x,y;
        while (m--) {
            // cin >> opt >> x >> y;
            scan("%s %d %d", opt , &x, &y);
            if (opt[0] == 'Q') {
                // cout << query(1, x, y) << endl;
                printf("%d\n", query(1, x, y));
            } else {
                update(1, x, y);
            }
        }
    }
    // pause;
    return 0;
}