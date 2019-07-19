#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;

int const maxn = 1e6 + 10;
int r[maxn];

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans += (x - 2);
        }
        cout << "Case " << ++ c << ": " << ans << endl;
    }
    // pause;
    return 0;
}