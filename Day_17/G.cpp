#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 200000;
vector<int> e[maxn];
int vis[maxn];
int x[maxn];
int cnt = 0;

struct node {
    int u, s;
    node(const int &u = 0,const int &v = 0) :
        u(u),s(v) {}
}; 

int bfs(int x, int n) {
    queue<node> q;
    q.push(node(x, 0));
    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if (t.u == n)
            return t.s;
        int v = t.u;
        vis[v] = 1;
        for (auto &u : e[v]) {
            if (!vis[u])
                q.push(node(u, t.s + 1));
        }
    }

    return 0;
}

int main(void) {
    FAST_IO;
    int n, m;
    cin >> n >>m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int ans = bfs(1, n);
    if (ans <= 2 && ans != 0)
        cout << "POSSIBLE" << endl;
    else 
        cout << "IMPOSSIBLE" << endl;
    // pause;
    return 0;
}