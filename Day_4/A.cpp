#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;

int const maxn = 40000 + 10;
struct node {
    int v, w, next;
}e[maxn * 2];
int cnt = 1, head[maxn * 2], fa[maxn][25];
int dis[maxn], dep[maxn], vis[maxn], n;

void add(int u, int v, int w){
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void init(){
    cnt = 1;
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(vis));
    memset(dis, 0, sizeof(dis));
    memset(dep, 0, sizeof(dep));
    memset(fa, 0, sizeof(fa));
}

void dfs(int u, int v){
    if (vis[u]) return;
    vis[u] = 1;
    fa[u][0] = v;
    for (int i = head[u]; i ; i = e[i].next){
        int x = e[i].v, w = e[i].w;
        if (v == x)
            continue;
        dep[x] = dep[u] + 1;
        dis[x] = dis[u] + w;
        dfs(x, u);
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
    if (dep[u] > dep[v]){
        swap(u, v);
    }
    for (int i = 20; i >= 0; i--){
        if ((dep[v] - (1 << i)) >= dep[u]){
            v = fa[v][i];
        }
    }
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--){
        if (fa[u][i] != fa[v][i]){
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[v][0];
}

int main(void) {
    FAST_IO;
    int t;
    cin >> t;

    while (t--) {
        int m;
        cin >> n >> m;
        init();
        for (int i = 0; i < n - 1; i++){
            int u, v, w;
            cin >> u >> v >> w;
            add(u, v, w);
            add(v, u, w);
        }
        dfs(1, 1);
        doubly();
        while (m--){
            int x, y;
            cin >> x >> y;
            cout << dis[x] + dis[y] - dis[lca(x, y)] * 2 << endl;
        }
    }
    // system("pause");
    return 0;
}