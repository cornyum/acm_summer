#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")

using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 100000 + 10;
int a[maxn], color[maxn], ans;
struct seg {
    int l, r;
    int v, tag;
    void update(int x) {
        v = x;
        tag = x;
    }
}tree[maxn << 2];

inline int lc(int x)  {return x << 1;}
inline int rc(int x)  {return x << 1 | 1;}

void push_up(int p) {
    tree[p].v = tree[lc(p)].v | tree[rc(p)].v;
}

void push_down(int p) {
    if (tree[p].tag) {
        int v = tree[p].v;
        tree[lc(p)].update(v);
        tree[rc(p)].update(v);
        tree[p].tag = 0;
    }
}

void bulid(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    tree[p].tag = tree[p].v = 0;
    if(l == r) {
        tree[p].v = 1;
        tree[p].tag = 0;
        return;
    }
    int mid = (l + r ) >> 1;
    bulid(lc(p), l, mid);
    bulid(rc(p), mid + 1, r);
    push_up(p);
}

void update(int p, int l, int r, int x) {
    if (l <= tree[p].l && r >= tree[p].r) {
        tree[p].update((1 << (x - 1)));
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

ll query(int p, int l, int r) {
    if(l <= tree[p].l && r >= tree[p].r) {
        return tree[p].v;
    }
    push_down(p);
    int ans = 0;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid)
        ans = ans | query(lc(p),l , r);
    if (r > mid)
        ans = ans | query(rc(p),l , r);
    return ans;
}

template<typename T>
inline bool scan_d(T &ret)
{
    char c; 
    int sgn;
    if(c=getchar(),c==EOF)
        return 0; 
    while(c!='-'&&(c<'0'||c>'9'))
    {
        c=getchar();
        if(c==EOF)
            return 0;
    } 
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') 
        ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
template<typename T>
inline void out(T x) 
{
    if(x>9) 
        out(x/10);
    putchar(x%10+'0');
}

int main(void) {
    int n, m, t;
    // scanf("%d %d %d", &n, &t, &m);
    scan_d(n);
    scan_d(t);
    scan_d(m);
    bulid(1, 1, n);
    while (m--) {
        char opt[8];
        int x, y;
        // scanf("%s %d %d", opt, &x, &y);
        scanf("%s", opt);
        scan_d(x);
        scan_d(y);
        if (x > y)
            swap(x, y);
        if(opt[0] == 'C') {
            int z;
            // scanf("%d", &z);
            scan_d(z);
            update(1, x, y, z);
        } else {
            int ans = query(1, x, y);
            int num = 0;
            while (ans) {
                if (ans & 1) num++;
                ans >>= 1;
            }
            // printf("%d\n", num);
            out(num);
            puts("");
        }
    }
    pause;
    return 0;
}