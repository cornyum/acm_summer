#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
int const maxn = 1e5 + 10;
vector<int> e[maxn];
int vis[maxn];
ll v1, v2;

void dfs(int v, ll n){
    if (vis[v])
        return;
    vis[v] = 1;
    if (n & 1) v1++;
    else v2++;
    for (int i = 0u; i < e[v].size(); i++) {
        dfs(e[v][i], n + 1);
    }
}

int main(void){
    FAST_IO;
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0LL);
    cout << v1 * v2 - (n - 1) << endl;
    // system("pause");
    return 0;
}

