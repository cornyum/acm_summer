#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef unsigned int UINT;
typedef long long ll;
using namespace std;
int const maxn = 400000 + 10;
ll const INF = LLONG_MAX;
struct Node {
    int v, w, next;
}e[maxn << 1];
int head[maxn], vis[maxn], cnt = 0;
ll dis[maxn];
int cnt_num[maxn];
int n;
struct node {
    int u;
    ll w;
    node(int const &u = 0, ll const &w = 0) : 
        u(u), w(w) { }
    bool operator<(const node &p) const{
        return w > p.w;
    }
};

void add(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dijkstra() {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    priority_queue<node> q;
    q.push(node(1, dis[1]));
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (dis[v] == dis[u] + w)
                cnt_num[v]++;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(node(v, dis[v]));
                cnt_num[v] = 1;
            }
        }
    }
}

pair<int, int> e2[maxn];

int main(void) {
    FAST_IO;
    memset(head, -1, sizeof(head));
    int m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    
    for (int i = 0; i < k; i++) {
        cin >> e2[i].first >> e2[i].second;
        add(1, e2[i].first, e2[i].second);
        add(e2[i].first, 1, e2[i].second);
    }

    dijkstra();

    int ans = 0;
    for (int i = 0; i < k; i++) {
        int v = e2[i].first;
        int w = e2[i].second;
        if (w > dis[v]) {
            ans++;
        } else if (w == dis[v]) {
            if (cnt_num[v] > 1) {
                ans++;
                cnt_num[v]--;
            }
        }
    }
    cout << ans << endl;

    // PAUSE;
    return 0;
}