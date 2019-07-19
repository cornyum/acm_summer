#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
#define INF 0x3f
using namespace std;
int const maxn = 1e6 + 10;

struct node {
    int v, w, next;
}e[maxn << 1];
int head[maxn], vis[maxn], cnt = 0;
int n, m, s, t;
ll dis[maxn];

void add(int u, int v, int w) {
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void spfa() {
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = e[i].next) {
            int v = e[i].v; 
            int w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

int main(void) {
    FAST_IO;
    memset(head, -1, sizeof(head));
    memset(dis, INF, sizeof(dis));
    
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    spfa();

    cout << dis[t] << endl;
    // PAUSE;
    return 0;
}