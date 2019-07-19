#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
int const maxn = 200 + 10;
int const inf = 0x3f;
int a[maxn], b[maxn];
int dp[maxn][maxn];

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    int tt = 0;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[i][j] = 0x3f3f3f3f;
            }
        }
        for (int l = 0; l <= n; l++){
            for (int i = 1; i + l <= n; i++) {
                int j = i + l;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k - 1] + a[k] + dp[k +1][j] + b[i - 1] + b[j + 1]);
                }
            }
        }
        cout << "Case #" << ++tt << ": " << dp[1][n] << endl;
    }

    // pause;
    return 0;
}
