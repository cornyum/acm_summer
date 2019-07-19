#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const INF = 0x3F;
int const maxn = 1e3 + 10;
struct node {
    int x, b;
    node(const int &x = 0, const int &b = 0) : x(x), b(b) {}
    bool operator<(const node &p) const {
        return x < p.x;
    }
}a[maxn];
ll dp[maxn][maxn][2], sum[maxn];

int main(void) {
    FAST_IO;
    int n, v, x;
    while (cin >> n >> v >> x) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].b;
        }
        a[n + 1].x = x;
        a[n + 1].b = 0;
        n++;
        sort(a + 1 , a + 1 + n);
        memset(dp, INF, sizeof(dp));
        sum[0] = 0;
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i].b;
            if (a[i].x == x && a[i].b == 0)
                dp[i][i][0] = dp[i][i][1] = 0;
        }
        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++){
                int j = i + l - 1;
                dp[i][j][0] = min(dp[i][j][0], 
                    dp[i + 1][j][0] + (a[i + 1].x - a[i].x) * (sum[i] + sum[n] - sum[j]));
                dp[i][j][0] = min(dp[i][j][0], 
                    dp[i + 1][j][1] + (a[j].x - a[i].x) * (sum[i] + sum[n] - sum[j]));
                dp[i][j][1] = min(dp[i][j][1], 
                    dp[i][j - 1][0] + (a[j].x - a[i].x) * (sum[i - 1] + sum[n] - sum[j - 1]));
                dp[i][j][1] = min(dp[i][j][1], 
                    dp[i][j - 1][1] + (a[j].x - a[j - 1].x) * (sum[i - 1] + sum[n] - sum[j - 1]));
            }
        }
        cout << min(dp[1][n][0], dp[1][n][1]) * v << endl;
    }

    // pause;
    return 0;
}
