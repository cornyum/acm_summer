#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
int const maxn = 100000 + 10;
inline int lc(int p) { return p << 1; }
inline int rc(int p) { return p << 1 | 1; }
int a[maxn];
ll b[maxn], c[maxn];

struct seg {
    int l, r, mid;
    ll sum;
    void update() {
        sum++;
    }
}tree[maxn << 2];

void push_up(int p) {
    tree[p].sum = tree[lc(p)].sum + tree[rc(p)].sum;
}

void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    tree[p].sum = 0;
    int mid = (l + r) >> 1;
    tree[p].mid = mid;
    if (r == l)
        return;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
    push_up(p);
}

void insert(int p, int x) {
    if (tree[p].l == tree[p].r && tree[p].l == x) {
        tree[p].update();
        return;
    }
    int mid = tree[p].mid;
    if (x <= mid)
        insert(lc(p), x);
    else 
        insert(rc(p), x);
    push_up(p);
}

ll query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    int mid = tree[p].mid;
    ll ans = 0;
    if (l <= mid)
        ans += query(lc(p), l, r);
    if (r > mid)
        ans += query(rc(p), l, r);
    return ans;
}

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int node_num = -1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            node_num = max(a[i], node_num);
        }
        bulid(1, 1, node_num);
        for (int i = 1 ; i<= n; i++) {
            insert(1, a[i]);
            b[i] = query(1, 1, a[i]) - 1;
        }
        bulid(1, 1, node_num);
        for (int i = n ; i >= 1; i--) {
            insert(1, a[i]);
            c[i] = query(1, 1, a[i]) - 1;
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (b[i] * (n - i - c[i])) + (c[i] * (i - 1 - b[i]));
        }
        cout << ans << endl;
    }
    // pause;
    return 0;
}

/*
5
2 3 4 5 1
 */