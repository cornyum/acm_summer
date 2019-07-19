#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<list>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1e5 + 10;
int a[maxn], b[maxn], pa[maxn], pb[maxn];
int n;

struct ST {
    vector<vector<int>> mn;
    void modify(int *a, int l, int r) {
        mn.resize(r + 1);
        int len = log2(r - l + 1) + 2;
        for (int i = l; i <= r; i++) {
            mn[i].resize(len);
            mn[i][0] = a[i];
        }
        for (int i = 1; l + (1 << i) - 1 <= r; i++) {
            for (int j = l; j + (1 << i) - 1 <= r; j++) {
                mn[j][i] = min(mn[j][i - 1], mn[j  + (1 << (i - 1))][i - 1]);
            }
        }
    }
    int queryMin(int l, int r) {
        int k = log2(r - l + 1);
        return min(mn[l][k], mn[r - (1 << k) + 1][k]);
    }
};
 
ST t, w;

bool dfs(int l, int r) {
    if (l > r)
        return 1;
    int posa = pa[t.queryMin(l, r)];
    int posb = pb[w.queryMin(l, r)];
    if (posa != posb)
        return 0;
    bool flag = 1;
    flag &= dfs(l, posa - 1);
    flag &= dfs(posb + 1, r);
    return flag;
}

bool check(int x) {
    return dfs(1, x);
}

int main(void) {
    // FAST_IO;

    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            pa[a[i]] = i;
        }
        for (int i = 1;  i <= n; i++) {
            scanf("%d", &b[i]);
            pb[b[i]] = i;
        }
        t.modify(a, 1, n);
        w.modify(b, 1, n);
        int l = 1, r = n + 1, m;
        while (l + 1 < r){
            m = (l + r) / 2;
            check(m) ? l = m: r = m;
        }
        printf("%d\n", l);
    }

    // pause;
    return 0;
}