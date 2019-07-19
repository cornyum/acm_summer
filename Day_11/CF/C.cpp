#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1e5 + 10;

ll n, m, k;
queue<ll> q;

int main() {
    FAST_IO;
    cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        ll x;
        cin >> x;
        q.push(x);
    }
    ll ans = 0, pre = 0;
    while(q.size()){
        ans++;
        ll num = 1;
        ll x = q.front(); 
        q.pop();
        ll blk = (x - 1 - pre) / k;
        while(q.size() && (q.front() - 1 - pre) / k == blk) {
            q.pop();
            num++;
        }
        pre += num;
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}