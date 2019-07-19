#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
int const maxn = 10000 + 10;
struct node
{
    int v, w,next;
}e[maxn << 1];
int cnt = 1, head[maxn], n, ans;
int dis[maxn], vis[maxn];

void add(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dp(int x){
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next){
        int y = e[i].v;
        if (vis[y])
            continue;
        dp(y);
        ans = max(ans, dis[x] + dis[y] + e[i].w);
        dis[x] = max(dis[x], dis[y] + e[i].w);
        // cout << ans << endl;
    }
}

int main(void) {
    FAST_IO;

    cin >> n;
    for (int i = 1; i < n; i++) {
        int v, w;
        cin >> v >> w;
        add(i, v, w);
        add(v, i, w);
    }


    system("pause");
    return 0;
}
