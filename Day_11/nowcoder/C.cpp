#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 1e3 + 10;
int a[maxn];
int main(void) {
    FAST_IO;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        int ans = 0;
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > x)
                flag = 0;
            if (a[i] <= x)
                flag = 1;
            if (flag == 1) {
                ans++;
                flag = 0;
            }
        }
        cout << ans << endl;
    }

    // system("pause");
    return 0;
}
