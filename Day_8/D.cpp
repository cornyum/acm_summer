#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cctype>

typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
#define INF 0x3f
using namespace std;
int const maxn = 100000 + 10;
struct node {
    int v, w, next;
}e[maxn << 1], g[maxn << 1];
struct Node {
    int u;
    ll w;
    Node(int const &u = 0, ll const &w = 0) : 
        u(u), w(w) { }
    bool operator<(const Node &p) const{
        return w > p.w;
    }
};
int head[maxn], vis[maxn], cnt = 0;
int dis[maxn], head2[maxn], cnt2 = 0;
int ans[maxn];

void add(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void add2(int u, int v, int w) {
    g[cnt2].v = v;
    g[cnt2].w = w;
    g[cnt2].next = head2[u];
    head2[u] = cnt2++;
}

void dijkstra(int s) {
    memset(vis, 0, sizeof(vis));
    memset(dis, INF, sizeof(dis));
    dis[s] = 0;
    priority_queue<Node> q;
    q.push(Node(s, dis[s]));
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(Node(v, dis[v]));
            }
        }
    }
}

int main(void) {
    FAST_IO;
    memset(head, -1, sizeof(head));
    memset(head2, -1, sizeof(head2));
    int n, m, x;
    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add2(v, u, w);
    }
    dijkstra(x);

    for (int i = 1; i <= n; i++){
        if (i == x) continue;
        ans[i] += dis[i];
    }

    memcpy(e, g, sizeof(g));
    memcpy(head, head2, sizeof(head2));
    dijkstra(x);
    
    int mx = -1;
    for (int i = 1; i <= n; i++){
        if (i == x) continue;
        ans[i] += dis[i];
        mx = max(ans[i], mx);
    }
    cout << mx << endl;
    // PAUSE;
    return 0;
}