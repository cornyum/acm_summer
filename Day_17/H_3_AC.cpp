#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1e5 + 10;
ll const INF = 0x3f3f3f3f3f3f3f3f;
int main(void) {
    FAST_IO;
    int n;
    int p, q, r;
    cin >> n >> p >> q >> r;
    ll s1 = -INF, s2 = -INF, s3 = -INF;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        s1 = max(s1, p * a);
        s2 = max(s2, s1 + q * a);
        s3 = max(s3, s2 + r * a);
    }
    cout << s3 << endl;
    // system("pause");
    return 0;
}