#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
int const maxn = 100010 * 2;
struct node {
    int v, next;
}e[maxn];
int dep[maxn >> 1], head[maxn], father[maxn >> 1], vis[maxn >> 1], fa[maxn >> 1][25];
map<string, int> mp;
int cnt = 1;
int n, m;

void add(int u, int v){
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void init(){
    memset(vis, 0, sizeof(vis));
    memset(head, 0, sizeof(head));
    memset(dep, 0, sizeof(dep));
    memset(fa, 0, sizeof(fa));
    cnt = 1;
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
}

int find(int x){
    return x == father[x] ? x : father[x] = find(father[x]);
}

void unio(int x, int y){
    int a = find(x), b = find(y);
    if (a != b){
        father[a] = b;
    }
}

void dfs(int u, int f){
    if (vis[u])
        return;
    vis[u] = 1;
    fa[u][0] = f;
    for (int i = head[u]; i; i = e[i].next){
        int v = e[i].v;
        if (v == f)
            continue;
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

int main(void){
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        string name1, name2;
        mp.clear();
        cin >> n >> m;
        int temp = 0;
        init();
        for (int i = 1; i < n; i++){
            cin >> name1 >> name2;
            if(mp.count(name1) == 0){
                mp[name1] = ++temp;
            }
            if(mp.count(name2) == 0){
                mp[name2] = ++temp;
            }
            int u = mp[name1], v = mp[name2];
            unio(u, v);
            add(u, v);
            add(v, u);
        }
        int root = find(1);
        dfs(root, root);
        doubly();

        while (m--){
            cin >> name1 >> name2;
            int u = mp[name1], v = mp[name2];
            int f = lca(u, v);
            if (u == v)
                cout << 0 << endl;
            else if (f == u){
                cout << 1 << endl;
            } else {
                int ans = dep[u] - dep[f];
                if (v != f) ans++;
                cout << ans << endl;
            }
        }
    }

    // system("pause");
    return 0;
}
/*
100
7 4
2 1 
3 1
4 2
6 3
5 3
7 3
4 3
4 1
1 4
4 4
 */