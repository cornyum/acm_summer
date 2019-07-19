#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;

ll pow_mod(ll a, ll x, ll mod) {
    if (!x) return 1;
    ll ans = pow_mod(a, x >> 1, mod);
    ans = ans * ans % mod;
    if (x & 1)
        ans = ans * x % mod;
    return ans % mod;
}

int main(void) {
    FAST_IO;
    ll m, n, a1, a2;
    cin >> m >> n >> a1 >> a2;


    system("pause");
    return 0;
}