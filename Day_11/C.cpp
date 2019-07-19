#include <bits/stdc++.h>
#define PAUSE system("pause")
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        priority_queue<ll, vector<ll>, greater<ll>> q;
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            q.push(x);
        }
        ll ans = 0;
        while (q.size() != 1) {
            ll x = q.top();
            q.pop();
            x += q.top();
            ans += x;
            q.push(x);
            q.pop();
        }
        cout << ans << endl;
        if(t != 0) cout << endl;
    }

    // PAUSE;
    return 0;
}