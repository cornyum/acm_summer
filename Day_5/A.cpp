#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 6000 + 10;
struct node {
    int v, next;
}e[maxn << 1];
int head[maxn], cnt = 1, dp[maxn][2], a[maxn];
int n, vis[maxn], in[maxn];

void add(int u, int v) {
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int u, int f) {
    if (vis[u]) return;
    vis[u] = 1;
    for (int i = head[u]; i ; i = e[i].next) {
        int v = e[i].v;
        if (v == f) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][1], dp[v][0]);
        dp[u][1] += dp[v][0];
    }
}

int main(void) {
    FAST_IO;
    while (cin >> n){
        memset(head, 0, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(in, 0, sizeof(in));
        cnt = 1;
        memset(dp, 0, sizeof(dp));
        for (int i = 1;  i <= n; i++){
            cin >> a[i];
            dp[i][1] = a[i];
        }
        for (int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            add(v, u);
            in[u]++;
        }
        int x, y;
        cin >> x >> y;
        int root;
        for (int i = 1; i <= n; i++)
        {
            if (!in[i]){
                root = i;
                break;
            }
        }
        dfs(root, root);
        // cout << root << endl;
        cout << max(dp[root][0], dp[root][1]) << endl;
    }

    // system("pause");
    return 0;
}