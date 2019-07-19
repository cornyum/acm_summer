#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 2e5 + 10;
struct node {
    int v, next;
}e[maxn << 1];
int cnt = 1, head[maxn], n;
ll size[maxn], dp[maxn];
ll ans;

void add(int u, int v) {
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

ll dfs(int u, int fa) {
    size[u] = 1;
    for (int i = head[u]; i; i = e[i].next){
        int v = e[i].v;
        if (v == fa) continue;
        size[u] += dfs(v, u);
        dp[u] += dp[v];
    }
    dp[u] += size[u];
    return size[u];
}

void dfs(int u, int fa, ll x) {
    ans = max(ans, dp[u] + n - size[u] + x);
    // cout << ans << endl;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (fa == v) continue;
        dfs(v, u, dp[u] - size[u] - dp[v] + x - size[v] + n);
    }
}

int main(void) {
    FAST_IO;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }

    dfs(1, -1);

    ans = dp[1];
    for (int i = head[1]; i; i = e[i].next) {
        int v = e[i].v;
        dfs(v, 1, dp[1] - dp[v] - size[v]);
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}