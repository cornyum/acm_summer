#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
const int maxn = 1e5 + 10;
int father[maxn];
ll s[maxn];
int n, m;
void init() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
        s[i] = 1;
    }
}

int find(int x) {
    return father[x] == x ? x : father[x] = find(father[x]);
}

void unio(int x, int y) {
    int a = find(x), b = find(y);
    if (a != b) {
        father[a] = b;
    }
}

struct node {
    int u, v;
    node(const int &u = 0, const int &v = 0) : u(u), v(v) {}  
}e[maxn];

int main(void) {
    FAST_IO;
    vector<int> ans;
    // cin >> n >> m;
    scanf("%d %d", &n , &m);
    init();
    for (int i = 0; i < m; i++) {
        // cin >> e[i].u >> e[i].v;
        scanf("%d %d", &e[i].u, &e[i].v);
    }
    ll set_num = 1LL * n * (n - 1) / 2;
    for (int i = m - 1; i >= 0; i--) {
        ans.push_back(set_num);
        int a = find(e[i].v), b = find(e[i].u);
        if (a != b) {
            set_num -= s[b] * s[a];
            father[a] = b;
            s[b] += s[a];
        }
    }
    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        // cout << *it << endl;
        printf("%d\n", *it);
    }
    
    // pause;
    return 0;
}