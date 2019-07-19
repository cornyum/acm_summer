#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
#define pause system("pause")
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
int const maxn = 100000 + 10;
struct SegmentTree{
    int l, r;
    ll data, tag;
}tree[maxn << 2];
ll a[maxn];
//递归建树
void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].data = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(p * 2, l, mid);
    bulid(p * 2 + 1, mid + 1, r);
    tree[p].data = tree[p * 2].data + tree[p * 2 + 1].data;
}
// lazy标记传递
void push_down(int p) {
    if (tree[p].tag) {
        tree[p * 2].data += tree[p].tag * (tree[p * 2].r - tree[p * 2].l + 1);
        tree[p * 2 + 1].data += tree[p].tag * (tree[p * 2 + 1].r - tree[p * 2 + 1].l + 1);
        tree[p * 2].tag += tree[p].tag;
        tree[p * 2 + 1].tag += tree[p].tag;
        tree[p].tag = 0; 
    }
}
// 区间更新
void update(int p, int l, int r, ll d) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].data += d * (tree[p].r - tree[p].l + 1);
        tree[p].tag += d;
        return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) update(p * 2, l, r, d);
    if (r > mid) update(p * 2 + 1, l ,r, d);
    tree[p].data = tree[p * 2].data + tree[p * 2 + 1].data;
}
//区间查询
ll query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r)
        return tree[p].data;
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    ll val = 0;
    if (l <= mid)
        val += query(p * 2, l, r);
    if (r > mid) 
        val += query(p * 2 + 1, l, r);
    return val;
}

int main(void) {
    FAST_IO;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bulid(1, 1, n);
    for (int i = 1; i <= m; i++) {
        int opt, x, y;
        ll k;
        cin >> opt >> x >> y;
        if(opt == 1) {
            cin >> k;
            update(1, x, y, k);
        } else {
            cout << query(1, x, y) << endl;
        }
    }

    // pause;
    return 0;
}
