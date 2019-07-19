#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
int const maxn = 100000 + 10;
int a[maxn], b[maxn];
int vis[maxn];
vector<int> e[maxn], ans;
void dfs(int u, int x, int y){
    if (vis[u]) return;
    vis[u] = 1;
    if ((a[u] ^ x) != b[u]){
        ans.push_back(u);
        x ^= 1;
    }
    for (int i = 0u; i < e[u].size(); i++){
        dfs(e[u][i], y, x);
    }
}

int main(void){
    FAST_IO;
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    dfs(1, 0, 0);
    cout << ans.size() << endl;

    for (auto &x : ans){
        cout << x << endl;
    }

    // system("pause");
    return 0;
}