#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
const int maxn = 2e5 + 10;

inline int lc(int x) { return x << 1; }
inline int rc(int x) { return x << 1 | 1; }

struct node {
    int pos;
    ll val;
    bool operator<(const node &p) const {
        if (val == p.val)
            return pos < p.pos;
        return val < p.val;
    }
}a[maxn];

struct seg {
    int l, r;
    ll sum;
}tree[maxn << 2];

void push_up(int p) {
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
}

void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    tree[p].sum = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
    push_up(p);
}

void update(int p, int pos) {
    if (tree[p].l == pos && tree[p].r == pos) {
        tree[p].sum++;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if(pos <= mid)
        update(lc(p), pos);
    else 
        update(rc(p), pos);
    push_up(p);
}

ll query(int p, int l, int r) {
    if(tree[p].l == l && tree[p].r == r) {
        return tree[p].sum;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (mid < l)
        return query(rc(p), l, r);
    else if (mid >= r)
        return query(lc(p), l, r);
    else 
        return query(lc(p), l, mid) + query(rc(p), mid + 1, r);
}

int main(void) {
    FAST_IO;
    ll n, k, x;
    cin >> n >> k;
    for (int i = 1; i<= n; i++) {
        cin >> x;
        x -= k;
        a[i].pos = i;
        a[i].val = a[i - 1].val + x;
    }
    sort(a + 1, a + 1 + n);
    bulid(1, 1, n);
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        update(1, a[i].pos);
        if (a[i].val >= 0)
            ans++;
        if (a[i].pos == 1)
            continue;
        ans += query(1, 1, a[i].pos - 1);
    }
    cout << ans << endl;
    pause;
    return 0;
}