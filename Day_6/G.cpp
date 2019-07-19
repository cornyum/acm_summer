#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 2e5 + 10;
struct node {
    int v, next;
}e[maxn << 1];
int cnt = 1, head[maxn], color[maxn], a[maxn], b[maxn];
int n, m;
vector<int> v1, v2;
void add(int u, int v){
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int u, int c) {
    if (color[u]) return;
    color[u] = c;
    if (color[u] == 1){
        v1.push_back(u);
    } else {
        v2.push_back(u);
    }
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if (!color[v])
            dfs(v, -c);
    }
}
 
int main(void) {
    // FAST_IO;
    int t;
    // cin >> t;
    scanf("%d", &t);
    while (t--) {
        // cin >> n >> m;
        scanf("%d %d", &n, &m);
        for (int i = 0 ; i<= n; i++){
            color[i] = head[i] = 0;
        }
        v1.clear();
        v2.clear();
        cnt = 1;
        for (int i = 0; i < m; i++) {
            int u, v;
            // cin >> u>> v;
            scanf("%d %d", &u, &v);
            add(u, v);
            add(v, u);
        }
        dfs(1, 1);
        if (v1.size() > v2.size()) {
            v1 = v2;
        }
        printf("%d\n", v1.size());
        for (int i = 0; i < v1.size() ;i++) {
            printf(i == 0 ? "%d" : " %d", v1[i]);
        }
        puts("");
    }
    // system("pause");
    return 0;
}