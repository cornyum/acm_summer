#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1000 + 10;
vector<int> e[maxn];
int vis[maxn], match[maxn], n, m, k;

bool dfs(int u) {
    for(auto &v : e[u]) {
        if (vis[v])
            continue;
        vis[v] = 1;        
        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= n + m; i++) {
        if (!match[i]) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i))ans++;
        }
    }
    return ans;
}

int main(void) {
    FAST_IO;
    while (cin >> k && k != 0) {
        cin >> m >> n;
        memset(e, 0, sizeof(e));
        for (int i = 0; i < k; i++) {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v + m);
        }
        int ans = hungarian();
        cout << ans << endl;
    }

    // system("pause");
    return 0;
}