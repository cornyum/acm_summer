#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
int const maxn = (1e5 + 1) * 2;
struct node {
    int v, next;
    node(int const &v = 0, const int &x = 0): v(v), next(x) {}
}e[maxn];
int cnt = 1, flag;
int head[maxn], pre[maxn], ans;
int dis[maxn], k;
vector<int> path;
void add(int u, int v){
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

bool dfs(int u){
    for (int i = head[u]; i; i = e[i].next){
        int v = e[i].v;
        if (v == pre[u])
            continue;
        if (!pre[v]){
            pre[v] = u;
            dis[v] = dis[u] + 1;
            if (dfs(v)) 
                return true;
        } else if (dis[u] - dis[v] >= k){
            ans = dis[u] - dis[v] + 1;
            for (int j = u; j != v; j = pre[j]){
                path.push_back(j);
            }
            path.push_back(v);
            return true;
        }
    }
    return false;
}

int main(void){
    FAST_IO;
    int n, m;
    cin >> n >> m >> k;
    int u, v;
    flag = 0;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    pre[v] = u;
    dfs(v);
    cout << ans << endl;
    for (int i = 0; i < path.size(); ++i){
        if (i != 0) cout << " ";
        cout << path[i];
    }
    cout << endl;

    // system("pause");
    return 0;
}