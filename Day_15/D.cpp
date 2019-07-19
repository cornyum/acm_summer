#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 5e4 + 10;
int const INF = 0x3f3f3f3f;

inline int lc(int x)  {return x << 1;}
inline int rc(int x)  {return x << 1 | 1;}
int a[maxn];
int Max = -INF, Min = INF;
struct seg
{
    int l, r;
    int min, max;
}tree[maxn << 2];

void push_up(int p) {
    tree[p].max = max(tree[lc(p)].max, tree[rc(p)].max);
    tree[p].min = min(tree[lc(p)].min, tree[rc(p)].min);
}

void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    tree[p].max = tree[p].min = 0;
    if (r == l) {
        tree[p].min = tree[p].max = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid +1, r);
    push_up(p);
}

void query(int p, int l, int r) {
    if (l <= tree[p].l && r >= tree[p].r) {
        Min = min(Min, tree[p].min);
        Max = max(Max, tree[p].max);
        return;
    }
    int mid = (tree[p].l + tree[p].r ) >> 1;
    if (l <= mid)
        query(lc(p), l, r);
    if (r > mid)
        query(rc(p), l, r);
}


int main(void) {
    FAST_IO;
    int n, m;
    // cin >> n >> m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        // cin >> a[i];
        scanf("%d", &a[i]);
    }
    bulid(1, 1, n);
    while (m--) {
        Max = -INF;
        Min = INF;
        int x, y;
        // cin >> x >> y;
        scanf("%d %d", &x, &y);
        query(1, x, y);
        // cout << Max - Min << endl;
        printf("%d\n", Max - Min);
    }
    // pause;
    return 0;
}