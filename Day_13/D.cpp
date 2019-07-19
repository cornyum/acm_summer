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
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
int const maxn = 1000;
char s[maxn];
int dp[maxn][maxn];

int main(void) {
    FAST_IO;
    while (cin >> s) {
        if (!strcmp(s, "end")) {
            break;
        }
        int mx = 0;
        int ans = 0;
        int len = strlen(s);
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= len; i++) {
            for (int l = 0; l + i < len; l++) {
                int r = l + i;
                if (s[l] == '(' && s[r] == ')' || s[l] == '[' && s[r] == ']')
                    dp[l][r] = dp[l + 1][r - 1] + 2;
                for (int j = 0; j < r; j++) {
                    dp[l][r] = max(dp[l][r], dp[l][j] + dp[j + 1][r]);
                }
            }
        }
        cout << dp[0][len - 1] << endl;
    }
    // pause;
    return 0;
}