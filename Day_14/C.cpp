#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define pause system("pause")
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
ll dp[12][1 << 11];
bool in_s[1 << 11];

int main(void) {
    FAST_IO;
    int n, m;
    while (cin >> n >> m && n) {
        for (int i = 0; i < (1 << m); i++) {
            bool cnt = 0, has_odd = 0;
            for (int j = 0; j < m; j++) {
                if ((i >> j) & 1) {
                    has_odd |= cnt;
                    cnt = 0;
                } else {
                    cnt ^= 1;
                }
            }
            in_s[i] = has_odd | cnt ? 0 : 1;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << m); j++) {
                dp[i][j] = 0;
                for (int k = 0; k < (1 << m); k++) {
                    if ((j & k) == 0 && in_s[j | k])
                        dp[i][j] += dp[i - 1][k];
                }
            }
        }
        cout << dp[n][0] << endl;
    }

    // pause;
    return 0;
}
