#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
int const maxn = 1000000 + 10;

int dp[10][20], a[10];

int dfs(int pos, int statu, int limit) {
    if (pos == 0)
        return 1;
    if (!limit && dp[pos][statu] != -1) return dp[pos][statu];
    int up = limit ? a[pos] : 9;
    int ans = 0;
    for (int i = 0; i <= up; i++) {
        if (statu && i == 2) {
            continue;
        }
        if (i == 4) continue;
        ans += dfs(pos - 1, i == 6, limit && i == up);
    }
    if (!limit) dp[pos][statu] = ans;
    return ans;
}

int solve(int num) {
    memset(dp, -1, sizeof(dp));
    int top = 0;
    while (num != 0) {
        a[++top] = num % 10;
        num /= 10;
    }
    return dfs(top, 0, 1);
}

int main(void) {
    FAST_IO;
    int x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;
        cout << solve(y) - solve(x - 1) << endl;
    }
    // pause;
    return 0;
}