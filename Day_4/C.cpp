#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = (500000 + 10);
int fa[maxn][23], head[maxn * 2];
int dep[maxn], vis[maxn];
struct node {
    int v, next;
}e[maxn * 2];
int cnt = 1, n, m;

void add(int u, int v){
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int u, int f){
    if (vis[u]) return;
    vis[u] = 1;
    fa[u][0] = f;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (v == f) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
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
    if (dep[u] > dep[v]) swap(u, v);
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

int main(void){
    // FAST_IO;
    scanf("%d %d", &n, &m);

    for (int i = 1; i < n; i++){
        int u, v;
        // cin >> u >> v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 1);
    doubly();
    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int f1 = lca(a, b);
        int f2 = lca(c, a);
        int f3 = lca(c, b);
        int ans;
        // cout << f1 << endl << f2 << endl << f3 << endl;
        if (f1 == f2) ans = f3;
        else if (f2 == f3) ans = f1;
        else ans = f2;
        // cout << ans << " " << dep[a] + dep[b] + dep[c] - dep[f1] - dep[f2] - dep[f3] << endl;
        printf("%d %d\n", ans, dep[a] + dep[b] + dep[c] - dep[f1] - dep[f2] - dep[f3]);
    }

    // system("pause");
    return 0;
}


/*
6 4 
1 2 
2 3 
2 4 
4 5 
4 6

 */