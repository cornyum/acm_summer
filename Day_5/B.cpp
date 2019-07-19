#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 100000 + 10;
struct node {
    int v, next;
}e[maxn << 1];
int cnt = 1, head[maxn], c[maxn], vis[maxn];

void add(int u, int v) {
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

int dfs(int u) {
    if (vis[u])
        return 0;
    vis[u] = 1;
    c[u]++;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        c[u] += dfs(v);
    }
    return c[u];
}

int main(void) {
    FAST_IO;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    if (n & 1){
        cout << -1 << endl;
    } else {
        dfs(1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            // cout << "c[" << i << "] = " << c[i] << endl;
            if (c[i] % 2 == 0) ans++;
        }
        cout << ans - 1 << endl;
    }

    system("pause");
    return 0;
}