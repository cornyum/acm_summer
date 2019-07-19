#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
// #define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 100000 + 10;

inline int lc(int x)  {return x << 1;}
inline int rc(int x)  {return x << 1 | 1;}
ll a[maxn];
struct seg {
    int l, r;
    ll sum;
    void update() {
        sum = sqrt(sum);
    }
}tree[maxn << 2];

void push_up(int p) {
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
}

void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    tree[p].sum = 0;
    if (l == r) {
        tree[p].sum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
    push_up(p);
}

void update(int p, int l, int r) {
    if (tree[p].l == tree[p].r) {
        tree[p].update();
        return;
    }
    if (tree[p].sum == (tree[p].r - tree[p].l + 1))
        return;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid)
        update(lc(p), l, r);
    if (r > mid)
        update(rc(p), l, r);
    push_up(p);
}

ll query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    ll ans = 0;
    if (l <= mid)
        ans += query(lc(p), l, r);
    if (r > mid)
        ans += query(rc(p), l, r);
    return ans;
}

int main(void) {
    // FAST_IO;
    int n, m;
    int t = 0;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n ;i++){
            scanf("%lld", &a[i]);
        }
        bulid(1, 1, n);
        int opt, x, y;
        scanf("%d", &m);
        printf("Case #%d:\n", ++t);
        while (m--) {
            scanf("%d %d %d", &opt, &x, &y);
            if(x > y)
                swap(x, y);
            if (opt == 0) {
                update(1, x, y);
            } else {
                printf("%lld\n", query(1, x, y));
            }
        }
        puts("");
    }

    pause;
    return 0;
}