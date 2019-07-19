#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0)
#define pause system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 1e3 + 10;
int const mod = 1e9 + 7;
int a[maxn];

ll pow_mod(int a, int x, int mod) {
    if (!x) return 1;
    ll ans = pow_mod(a, x >> 1, mod);
    ans = ans * ans % mod;
    if (x & 1) {
        ans = ans * x % mod;
    }
    return ans;
}

using namespace std;
int main(void) {
    FAST_IO;
    int n;
    while (cin >> n) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

    }
    
    pause;
    return 0;
}