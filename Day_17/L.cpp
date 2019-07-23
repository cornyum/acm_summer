#include <iostream>
using namespace std;

int const MOD = 1000000007 ;
 long long pow_mod (long long a, long long x, long long mod) {
    if (x == 0)
        return 1;
 long long ans = pow_mod(a, x >> 1, mod);
    ans = ans * ans % mod;
    if(x % 2 == 1) ans = ans * a % mod;
    return ans;
}

int main(void) {
 long long n;
    while (cin >> n) {
     long long ans = 0;
        ans = pow_mod(2, n * n - 1, MOD) % MOD;
        cout << ans << endl;
    }
    return 0;
}