// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
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
    ll sum;
    void update(ll value) {
        sum += value * (r - l + 1);
        tag += value;
    }
}tree[maxn << 2];
ll a[maxn];
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
    tree[p].l = l, tree[p].r = r;
    tree[p].sum = 0;
    if (l == r) {
        tree[p].sum = a[l];
        return;
    }
    int mid = (l +r) >> 1;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
    push_up(p);
}

ll query(int p, int l, int r) {
    if(l <= tree[p].l && r >= tree[p].r) {
        return tree[p].sum;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    push_down(p);
    ll ans = 0;
    if (l <= mid) {
        ans += query(lc(p), l, r);
    }
    if(r > mid) {
        ans += query(rc(p), l, r);
    }
    return ans;
}

void update(int p, int l, int r, ll x) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].update(x);
        return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) 
        update(lc(p), l, r, x);
    if (r > mid) 
        update(rc(p), l, r, x);
    push_up(p);
}

int main(void) {
    FAST_IO;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    bulid(1, 1, n);
    char opt;
    int x, y;
    while (m--) {
        cin >> opt >> x >> y;
        if (opt == 'Q') {
            cout << query(1, x, y) << endl;
        } else {
            ll c;
            cin >> c;
            update(1, x, y, c);
        }
    }
    // pause;
    return 0;
}