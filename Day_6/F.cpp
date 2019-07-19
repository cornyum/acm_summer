#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int n, m;
char mp[53][53];
int dir[4][2] = {1, 0,-1 , 0, 0, 1, 0, -1}, tot = 0;
int vis[53][53];
 
bool check(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) 
        return false;
    return true;
}

void dfs(int x,int y) {
    if (vis[x][y]) return;
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int tx = x + dir[i][0];
        int ty = y + dir[i][1];
        if (check(tx, ty) && !vis[tx][ty] && mp[tx][ty] == '#') {
            dfs(tx, ty);
        }
    }
}

void connect() {
    for (int i = 0; i < n ;i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '#' && !vis[i][j]){
                tot++;
                dfs(i ,j);
            }
        }
    }
}
 
int main(void) {
    FAST_IO;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> mp[i];
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '#') {
                cnt++;
            }
        }
    }
    // cout << cnt << endl;
    if (cnt == 3)
        cout << 1 << endl;
    else if (cnt > 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mp[i][j] == '#') {
                    tot = 0;
                    memset(vis, 0, sizeof(vis));
                    mp[i][j] = '.';
                    connect();
                    mp[i][j] = '#';
                    if (tot != 1) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag) break;
        }
        if (flag) {
            cout << 1 << endl;
        } else {
            cout << 2 << endl;
        }
    } else {
        cout << -1 << endl;
    }
    
    // system("pause");
    return 0;
}

/*
5 5
###..
###..
..###
...##
...##

 */