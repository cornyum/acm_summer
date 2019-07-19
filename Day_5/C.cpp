// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef unsigned int UINT;
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int const maxn = 20000 + 10;
int const inf = 0x3f3f3f3f;
int n;
struct node {
    int v, next;
}e[maxn << 1];
int head[maxn], cnt = 1, size[maxn], ans_node, max_num, vis[maxn];

void add(int u, int v) {
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

int dp(int u) {
    if(vis[u])
        return 0;
    vis[u] = 1;
    size[u] = 1;
    int max_part = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (!vis[v]){
            size[u] += dp(v);
            max_part = max(max_part, size[v]);
        }
    }
    max_part = max(max_part, n - size[u]);
    if (max_part < max_num) {
        max_num = max_part;
        ans_node = u;
    }
    return size[u];
}

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ans_node = 0;
        max_num = inf;
        cnt = 1;
        memset(head, 0, sizeof(head));
        memset(vis, 0, sizeof(vis));
        memset(size, 0, sizeof(size));
        cnt = 1;
        // cout << n << endl;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        // cout << endl ;
        // vis[1] = 1;
        dp(1);
        // for (int i = 1; i <= n; i++)
        //     cout << size[i] << endl;
        cout << ans_node << ' ' << max_num << endl;
    }

    // system("pause");
    return 0;
}