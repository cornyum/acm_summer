#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 1e3 + 10;
int const mod = 1e9 + 7;
ll sum[maxn];
ll a[maxn][maxn];

int main(void) {
    FAST_IO;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        ll t = 0;
        for (int j = 1; j <= i; j++) {
            if (j == 1 || j == i) {
                a[i][j] = i % mod;
            } else {
                a[i][j] = (a[i - 1][j - 1] + a[i - 1][j]) % mod;
            }
            t += a[i][j];
            t %= mod;
        }
        sum[i] = (sum[i - 1] + t) % mod;
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cout << (sum[y] - sum[x - 1] + mod) % mod << endl; 
    }
    // system("pause");
    return 0;
}