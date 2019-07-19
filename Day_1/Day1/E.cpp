#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k, p;
int a[N], vis[N], ans[N], pos[N];
int pre[N], nxt[N];

int nxt_max() {
    while(vis[p]) p--;
    return p;
}

void del(int x) {
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
    vis[a[x]] = 1;
}

int main() {
    cin >> n >> k;
    p = n;
    for (int i = 1; i <= n; i++) (cin >> a[i]), pos[a[i]] = i;
    for (int i = 1; i <= n + 1; i++) pre[i] = i - 1;
    for (int i = 0; i <= n; i++) nxt[i] = i + 1;
    int tag = 1;
    while (nxt_max()) {
        int now = pos[p];
        int tmp = pre[now];
        int cnt = k;
        while (cnt-- && tmp > 0) {
            del(tmp);
            ans[tmp] = tag;
            tmp = pre[tmp];
        }
        cnt = k;
        tmp = nxt[now];
        while(cnt-- && tmp < n + 1) {
            del(tmp);
            ans[tmp] = tag;
            tmp = nxt[tmp];
        }
        del(now);
        ans[now] = tag;
        tag = 3 - tag;
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << endl;
    return 0;
}
