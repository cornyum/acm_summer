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
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 32 *32 + 10;
int n, m, k;

vector<int> e[maxn];
int a[32][32];
int dir[4][2] = {1, 0,-1 , 0, 0, 1, 0, -1}, vis[maxn];
int match[maxn];

bool check(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m) 
        return false;
    if (a[x][y] == -1) return false;
    return true;
}

bool dfs(int u) {
    for (int i = 0; i < e[u].size(); i++) {
        int v = e[u][i];
        if (vis[v]) continue;
        vis[v] = 1;
        if (!match[v] || dfs(match[v])) {
            match[u] = v;
            match[v] = u;
            return true;
        }
    }
    return false;
}

int hungarian() {
    int ans = 0;
    memset(match, 0, sizeof(match));
    for (int i = 1; i <= n * m - k; i++) {
        if (!match[i]) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i))ans++;
        }
    }
    return ans;
}

int main(void) {
    FAST_IO;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> y >> x;
        a[x][y] = -1;
    }

    int c = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != -1) {
                if ((i + j) % 2 == 1) {
                    a[i][j] = ++c;
                } else {
                    a[i][j] = ++c;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != -1 && (i + j) % 2 == 0) {
                for (int k = 0; k < 4; k++) {
                    int tx = i + dir[k][0];
                    int ty = j + dir[k][1];
                    if (check(tx, ty)) {
                        e[a[i][j]].push_back(a[tx][ty]);
                        e[a[tx][ty]].push_back(a[i][j]);
                    }
                }
            }
        }
    }

    int ans = hungarian();
    if (ans * 2 == n * m - k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    PAUSE;
    return 0;
}