#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
int const maxn = 1e5 + 10;
vector<int> e[maxn];
int color[maxn];
int flag;

void dfs(int v, int c){
    color[v] = c;
    for (int i = 0u; i < e[v].size(); i++){
        if (color[e[v][i]] == color[v]){
            flag = 0;
        }
        if (!color[e[v][i]]){
            dfs(e[v][i], -c);
        }
    }
}

int main(void)
{
    FAST_IO;
    int t;
    cin >> t;
    for (int q = 1; q <= t; q++){
        memset(color, 0, sizeof(color));
        for(int i = 0; i < maxn; i++)
            e[i].clear();
        int n, m, s;
        cin >> n >> m >> s;
        flag = 1;
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(s, 1);
        if (!flag){
            cout << "Case " << q << ": " << "YES" << endl;
        } else {
            cout << "Case " << q << ": " << "NO" << endl;
        }
    }

    // system("pause");
    return 0;
}