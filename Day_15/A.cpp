#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
const int maxn = 50000 + 10;
ll a[maxn];

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return x << 1 | 1;
}

struct seg {
    int l, r;
    ll data;
    void update(ll value) {
        data += value * (r - l + 1);
    }
}tree[maxn << 2];

void push_up(int p) {
    tree[p].data = tree[lc(p)].data + tree[rc(p)].data;
}

void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    tree[p].data = 0;
    if (l == r) {
        tree[p].data = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
    push_up(p);
}

void update(int p, int x, ll v) {
    if (tree[p].l == tree[p].r) {
        tree[p].update(v);
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (x <= mid) 
        update(lc(p), x, v);
    else 
        update(rc(p), x ,v);
    push_up(p);
} 

ll query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].data;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    ll ans = 0;
    if (l <= mid)
        ans += query(lc(p), l, r);
    if(r > mid)
        ans += query(rc(p), l, r);
    return ans;
}

int main(void) {
    FAST_IO;
    int t;
    scanf("%d", &t);
    int nn = 0;
    while (t--) {
        char opt[20];
        int n;
        scanf("%d", &n);
        for (int i = 1; i<= n; i++)
            scanf("%d", &a[i]);
        bulid(1, 1, n);
        printf("Case %d:\n", ++nn);
        while (scanf("%s", opt) && opt[0] != 'E') {
            int x, y;
            scanf("%d %d", &x, &y);
            if (opt[0] == 'A') {
                update(1, x, y);
            } else if (opt[0] == 'S') {
                update(1, x, -y);
            } else {
                printf("%d\n", query(1, x, y));
            }
        }
    }
    // pause;
    return 0;
}
