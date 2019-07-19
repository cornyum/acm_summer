#include <bits/stdc++.h>
#define PAUSE system("pause")
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
const int maxn = 100000 + 10;
int Next[maxn];
char a[maxn], b[maxn];
int vis[maxn];
int const MOD = 1000000007;
int dp[maxn];

void getNext(int len) {
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < len) {
        if(j == -1 || b[i] == b[j]) {
            i++;
            j++;
            Next[i] = j;
        } else {
            j = Next[j];
        }
    }
}

int KMP(int lena, int lenb) {
    int ans = 0;
    int i = 0, j = 0;
    while (i < lena) {
        if (j == -1 || a[i] == b[j]) {
            i++;
            j++;
            if (j == lenb) {
                ans++;
                vis[i] = i - j;
                j = Next[j];
            }
        } else {
            j = Next[j];
        }
    }
    return ans;
}

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    int n = 0;
    while (t--) {
        memset(vis, -1, sizeof(vis));
        memset(dp, 0, sizeof(dp));
        cin >> a >> b;
        int lenb = strlen(b);
        int lena = strlen(a);
        getNext(lenb);
        int cnt = KMP(lena, lenb);
        // cout << cnt << endl;
        dp[0] = 1;
        for (int i = 1; i <= lena; i++) {
            dp[i] = dp[i - 1];
            dp[i] %= MOD;
            if (vis[i] != -1) {
                dp[i] += dp[vis[i]] % MOD;
            }
            dp[i] %= MOD;
        }
        cout << "Case #" << ++n << ": " << dp[lena] << endl;
    }

    // PAUSE;
    return 0;
}