#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
int const maxm = 1e5 + 3;
int const maxn = 1e5 + 3;
struct node {
    int v, w, next;
    node(const int &v = 0, const int &w = 0) : v(v), w(w) {}
}e[maxm * 2 * 10];

int vis[maxn], flag, cnt = 1, head[maxm], father[maxn], dis[maxn], ans;
void add(int u, int v, int w){
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void init(int n)
{
    flag = 0;
    ans = 0;
    cnt = 1;
    head[0] = 0;
    memset(dis, 0, sizeof(dis));
    memset(head, 0, sizeof(head));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
}

int find(int x){
    return father[x] == x ? x : father[x] = find(father[x]);
}

void unio(int x, int y) {
    int a = find(x);
    int b = find(y);
    if (a == b){
        flag = 1;
    } else {
        father[a] = b;
    }
}

void dp(int x){
    vis[x] = 1;
    for (int i = head[x]; i; i = e[i].next){
        int y = e[i].v;
        if (vis[y])
            continue;
        dp(y);
        ans = max(ans, dis[x] + dis[y] + e[i].w);
        // cout << ans << endl;
        dis[x] = max(dis[x], dis[y] + e[i].w);
    }
}

int main(void){
    FAST_IO;
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF){
        init(n);
        int u, v, w;
        for (int i = 0; i < m; i++){
            scanf("%d %d %d", &u, &v, &w);
            unio(u, v);
            add(u, v, w);
            add(v, u, w);
        }
        if (flag) {
            printf("YES\n");
        } else {
            for (int i = 1; i <= n; i++){
                if (!vis[i]) {
                    dp(i);
                }
            }
            // dfs(1);
            printf("%d\n", ans);
        }
    }

    // system("pause");
    return 0;
}
/**
7 4
1 2 8
1 3 3
2 4 1
6 7 15

6 5
1 2 1
1 3 8
2 5 10
3 4 1
3 6 1
 */