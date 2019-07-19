#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
using namespace std;
int const maxn = 220;
int n, vis[maxn], match[maxn];
int a[maxn][maxn];
vector<int> e[maxn];

bool dfs(int u) {
    for (int i = 1; i <= n ;i++) {
        if(vis[i] || a[u][i] == 0) 
            continue;
        vis[i] = 1;
        if (!match[i] || dfs(match[i])){
            match[i] = u;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)){
            ans++;
        }
    }
    return ans;
}

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        int ans = hungarian();
        // cout << ans << endl;
        if (ans == n) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    PAUSE;
    return 0;
}