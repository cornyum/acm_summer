#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 20;
int dp[maxn][maxn][maxn], a[maxn];

ll dfs(int pos, int statu, int limit, int mod) {
    if (pos == 0) 
        return mod == 0 && statu == 2;
    if (!limit && dp[pos][statu][mod] != -1)
        return dp[pos][statu][mod];
    ll ans = 0;
    int up = limit ? a[pos] : 9;
    for (int i = 0; i <= up; i++) {
        int m = (mod * 10 + i) % 13;
        if (statu == 0 || statu == 1 && i != 3) {
            ans += dfs(pos - 1, i == 1, limit && i == up, m);
        } else {
            ans += dfs(pos - 1, 2, limit && i == up, m);
        }
    }
    if (!limit) dp[pos][statu][mod] = ans;
    return ans;
}

ll solve(int num) {
    memset(dp, -1, sizeof(dp));
    int top = 0;
    while (num) {
        a[++top] = num % 10;
        num /= 10;
    }
    return dfs(top, 0, 1, 0);
}

int main(void) {
    FAST_IO;
    ll n;
    while (cin >> n) {
        cout << solve(n) << endl;
    }
    // pause;
    return 0;
}