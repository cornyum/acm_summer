#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 2e5+10;
struct node {
    int u, v, w;
    bool operator<(const node &p) const {
        return w < p.w;
    }
}e[maxn], t[maxn];
struct Node{
    int v, w, next;
}g[maxn << 1];
int cnt = 1, head[maxn], fa[maxn][24], mx[maxn][24], f[maxn];
int n, m;
int vis[maxn], dep[maxn];

int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

void unio(int x, int y){
    int a = find(x), b = find(y);
    if (a != b) {
        f[a] = b;
    }
}

void init() {
    for (int i = 1; i <= n; i++)
        f[i] = i;
}

void add(int u, int v, int w){
    g[cnt].v = v;
    g[cnt].w = w;
    g[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int u, int f){
    if (vis[u]) return;
    vis[u] = 1;
    fa[u][0] = f;
    for (int i = head[u]; i; i = g[i].next) {
        int v = g[i].v;
        int w = g[i].w;
        if (v == f)
            continue;
        mx[v][0] = w;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

void doubly() {
    for (int j = 1; j <= 20; j++) {
        for (int i = 1; i <= n; i++) {
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
            mx[i][j] = max(mx[i][j - 1], mx[fa[i][j - 1]][j - 1]);
        }
    }
}

int lca(int u, int v){
    if (dep[u] > dep[v])
        swap(u, v);
    
    int ans = -1;
    for (int i = 20; i >= 0; i--){
        if (dep[fa[v][i]] >= dep[u]){
            ans = max(ans, mx[v][i]);
            v = fa[v][i];
        }
    }
    if (u == v) return ans;
    for (int i = 20; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]){
            ans = max(ans, mx[u][i]);
            ans = max(ans, mx[v][i]);
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    // cout << fa[v][0] << endl;
    ans = max(ans, mx[u][0]);
    ans = max(ans, mx[v][0]);
    // cout << ans << endl;
    return ans;
}

int main(void){
    FAST_IO;
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> e[i].u >> e[i].v >> e[i].w;
    }
    memcpy(t, e, sizeof(e));
    sort(e, e + m);
    ll s = 0;
    for (int i = 0; i < m; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int a = find(u), b = find(v);
        if (a != b) {
            // cout << u << " " << v << endl;
            f[a] = b;
            s += w;
            add(u, v, w);
            add(v, u, w);
        }
    }
    // cout << s << endl;
    dfs(1,1);
    doubly();
    // cout << s << endl;
    for (int i = 0; i < m; i++) {
        cout << s + t[i].w - lca(t[i].u, t[i].v) << endl;
    }

    // system("pause");
    return 0;
}