#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
int const maxn = 500 + 10;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int dp[maxn][maxn];
ll a[maxn], b[maxn];

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        memset(dp, 0, sizeof(dp));
        int n, m;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        int maxl = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i] == b[j]) {
                    for (int k = 0; k < j; k++) {
                        if (a[i] > b[k])
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + 1);
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
                maxl = max(dp[i][j], maxl);
            }
        }
        cout << maxl <<endl;
        if (t) cout << endl;
    }
    // pause;
    return 0;
}