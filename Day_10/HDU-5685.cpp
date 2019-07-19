#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 100000 + 10;
int const MOD = 9973;
char s[maxn];
int h[maxn];

int pow_mod(int a, int x, int mod) {
    if (x == 0)
        return 1;
    int ans = pow_mod(a, x >> 1, mod);
    ans = ans * ans % mod;
    if (x & 1) {
        ans = ans * a % mod;
    }
    return ans;
}

void has(char * str) {
    h[0] = 1;
    int len = strlen(str);
    for (int i = 1; i <= len; i++) {
        h[i] = (h[i - 1] * (str[i - 1] - 28)) % MOD;
    }
}

using namespace std;
int main(void) {
    // FAST_IO;
    int n;
    while (scanf("%d", &n) != EOF) {
        scanf("%s", s + 1);
        has(s + 1);
        for (int i = 0; i < n; i++) {
            int l, r;
            scanf("%d %d", &l, &r);
            printf("%d\n", (h[r] * pow_mod(h[l - 1], MOD - 2, MOD)) % MOD);
        }
    }

    // PAUSE;
    return 0;
}