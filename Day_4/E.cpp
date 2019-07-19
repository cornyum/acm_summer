// #include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
int const maxn = 1e5 + 10;
struct node {
    int v, next;
    node(const int &v = 0, int const & next = 0) : v(v), next(next) {}
}e[maxn * 2];
int head[maxn * 2], cnt = 1, dep[maxn];
int vis[maxn], fa[maxn][21], dis[maxn];
int n, m;
int ans = 0;
void add(int u, int v)
{
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs1(int u, int f){
    if (vis[u]) return;
    vis[u] = 1;
    fa[u][0] = f;
    for (int i = head[i]; i; i = e[i].next){
        int v = e[i].v;
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        dfs1(v, u);
    }
}

void doubly(){
    for (int j = 1; j <= 20; j++){
        for (int i = 1; i <= n; i++){
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v){
    if (dep[u] > dep[v])
        swap(u, v);

    for (int i = 20; i >= 0; i--){
        if ((dep[v] - (1 << i)) >= dep[u]){
            v = fa[v][i];
        }
    }
    if (u == v) return u;
    for (int i = 20; i >= 0; i--){
        if (fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[v][0];
}

int dfs2(int u, int f){
    if (vis[u])
        return 0;
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next){
        int v = e[i].v;
        if (v == f) continue;
        dis[u] += dfs2(v, u);
    }
    if (dis[u] == 0 && u != 1){
        ans += m;
    } else if (dis[u] == 1)
        ans++;
    return dis[u];
}

int main(void){
    // FAST_IO;
    // cin >> n >> m;
    scanf("%d %d", &n ,&m);

    for (int i = 1; i < n; i++){
        int u, v;
        // cin >> u >> v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs1(1, 1);
    doubly();
    for (int i = 0; i < m; i++){
        int u, v;
        // cin >> u >> v;
        scanf("%d %d", &u, &v);
        dis[u]++;
        dis[v]++;
        dis[lca(u, v)] -= 2;
    }
    // int ans = 0;
    memset(vis, 0, sizeof(vis));
    dfs2(1, 0);
    // cout << ans << endl;
    printf("%d\n", ans);
    // system("pause");
    return 0;
}