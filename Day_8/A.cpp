#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
typedef unsigned long long ull;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
using namespace std;

int const maxn = 1e4 + 10;
int const INF = 0x3f;

struct Node {
    int v, w, next;
}e[maxn << 1];
struct node {
    int u;
    ll w;
    node(int const &u = 0, ll const &w = 0) : 
        u(u), w(w) {}
    bool operator<(const node &p) const{
        return w > p.w;
    }  
};

int head[maxn], vis[maxn];
ll dis[maxn];
int cnt = 0;
int n, m, s, t;

void add(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dijkstra() {
    priority_queue<node> q;
    dis[s] = 0;
    q.push(node(s, dis[s]));
    while (!q.empty()) {
        int u = q.top().u;
        q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v;
            int w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push(node(v, dis[v]));
            }
        }
    }
}

int main(void) {
    FAST_IO;
    memset(head, -1, sizeof(head));
    memset(dis, INF, sizeof(head));

    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    dijkstra();
    cout << dis[t] << endl;

    PAUSE;
    return 0;
}