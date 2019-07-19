#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
int const MOD = 1e9 + 7;
int const maxn = 2e5 + 10;

ll pow_mod(ll a, ll x, ll mod)
{
    if (x == 0) return 1;
    ll ret = pow_mod(a, x >> 1, mod);
    ret = ret * ret % mod;
    if (x & 1) ret = ret * a % mod;
    return ret;
}
struct node {
    int e, v;
    node(int e, int v) : e(e), v(v) {}
};
vector<node> a;

int main(void) {
    // FAST_IO;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int e, v;
        scanf("%d %d", &v, &e);
        a.push_back(node(e, v));
    }
    sort(a.begin(), a.end(), [](node &x, node &y){
        return 1.0 * x.e * y.v > 1.0 * y.e * x.v;
    });
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d\n", (pow_mod(a[i].v, MOD - 2, MOD) * a[i].e) % MOD);
        // cout << (pow_mod(a[i].v, MOD - 2, MOD) * a[i].e) % MOD << endl;
    }
    // cout << endl;

    // system("pause");
    return 0;
}