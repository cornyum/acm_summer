#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;

struct node {
    ll x, w;
    node (const ll &x = 0, const ll &w = 0) :
        x(x), w(w) {}
    bool operator<(const node &p) const {
        if (w != p.w)
            return w > p.w;
        return x > p.x;
    }
};

int main(void) {
    FAST_IO;
    int n, k;
    cin >> n>> k;
    priority_queue<node> q;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        q.push(node(1, x));
    }
    int len = 0;
    if ((n - 1) % (k - 1) != 0) {
        len = k - 1 - (n - 1) % (k - 1);
    }

    for (int i = 0; i < len; i++) {
        q.push(node(1, 0));
    }
    ll ans = 0;
    while (q.size() != 1) {
        ll t = 0, max_len = -1;
        for (int i = 0; i < k; i++) {
            t += q.top().w;
            max_len = max(max_len, q.top().x);
            q.pop();
        }
        ans += t;
        q.push(node(max_len + 1, t));
    }
    cout << ans << endl;
    cout << q.top().x - 1 << endl;

    // pause;
    return 0;
}