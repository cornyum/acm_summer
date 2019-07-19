#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 10;
int a[maxn][maxn];
int n;
int vis[maxn][maxn];
set<int> st;
void dfs(int x, int y, ll s) {
    if (vis[x][y] || x > n || y > n || x <= 0 || y <= 0)
        return;
    if (x == n && y == n) {
        st.insert(s + a[x][y]);
    }
    vis[x][y] = 1;
    dfs(x + 1, y, s + a[x][y]);
    vis[x][y] = 0;
    dfs(x, y + 1, s + a[x][y]);
}

int main(void) {
    FAST_IO;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    dfs(1, 1, 0);
    cout << st.size() <<endl;

    // system("pause");
    return 0;
}