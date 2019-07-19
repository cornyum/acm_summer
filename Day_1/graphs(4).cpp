#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
struct node {
    int v, w;
    node(const int &v = 0, const int &w = 0) : v(v), w(w) {}
};
int const maxn = 110;
vector<node> e[maxn];
int vis[maxn], sum;

void dfs(int u, int v){
    vis[u] = 1;
    for (int i = 0u; i < e[u].size(); ++i){
        if (vis[e[u][i].v] == 1 || v == e[u][i].v){
            continue;
        }
        sum += e[u][i].w;
        
        dfs(e[u][i].v, u);
    }
}

int main(void){
    FAST_IO;
    int n;
    cin >> n; 
    int cnt = 0;
    int u, v, w;
    for (int i = 0; i < n; i++){
        cin >> u >> v >> w;
        cnt += w;
        e[u].push_back(node(v, w));
        e[v].push_back(node(u, 0));
    }
    sum = 0;
    dfs(u, v);
    // cout << sum << " " << cnt << endl;
    cout << min(sum, cnt - sum) << endl;

    // system("pause");
    return 0;
}