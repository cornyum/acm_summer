// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cctype>

#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
using namespace std;
int const maxn = 100 + 10;
vector<int> e[maxn];
int a[maxn], b[maxn], vis[maxn];
int match[maxn], n, mp[maxn][maxn];

bool dfs(int u) {
    // vis[u] = 1;
    for (int i = 0u; i < e[u].size(); i++){
        int v = e[u][i];
        if (vis[v]) continue;
        vis[v] = 1;
        if (!match[v] || dfs(match[v])) {
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= 2 * n; i++) {
        memset(vis, 0, sizeof(vis));
        if (!match[i]){
            if (dfs(i)){
                ans++;
            }
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
        int cnt = 0;
        for (int i = 1; i <=2 * n; i++) {
            e[i].clear();
        }
        // memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (a[i] == 0) b[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0 || b[i] == 0)
                cnt++;
            for (int j = 1; j <= n; j++) {
                cin >> mp[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (b[i] == 0 && a[j] && (mp[i][j] || i == j)) {
                    e[i].push_back(n + j);
                    e[n + j].push_back(i);
                }
            }
        }
        
        int ans = hungarian();
        if (ans == cnt) {
            cout << "^_^" << endl;
        } else {
            cout << "T_T" << endl;
        }
    }

    // PAUSE;
    return 0;
}