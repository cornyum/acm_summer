#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
#define INF 0x3f
using namespace std;
int const maxn = 1e2 + 10;
int dis[maxn][maxn], g[maxn][maxn];
int n;

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main(void) {
    FAST_IO;
    memset(dis, INF, sizeof(dis));
    int m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    floyd();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (j != 1) cout << ' ';
            cout << dis[i][j];
        }
        cout << endl;
    }

    // PAUSE;
    return 0;
}