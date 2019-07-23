#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 100;
int d[maxn], fa[maxn];

void init() {
    for (int i = 1; i < maxn; i++) {
        fa[i] = i;
        d[i] = 0;
    }
}

int find(int x) {
    if (x == fa[x])
        return x;
    int root = find(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = root;
}

int main(void) {
    FAST_IO;
    int n;
    while (cin >> n) {
        init();
        int flag = 0;
        int cnt = 0;
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            if (mp.count(a) == 0)
                mp[a] = ++cnt;
            if (mp.count(b) == 0)
                mp[b] = ++cnt;
            int u = mp[a], v = mp[b];
            int fx = find(u), fy = find(v);
            if (fx != fy) {
                fa[fx] = fy;
                d[fx]++;
            } else if (!flag){
                if (d[u] - d[v] < 0) {
                    flag = 1;
                    cout << a << " " << b << endl;
                }
            }
        }
        if (!flag) {
            cout << 0 << endl;
        }
    }
    // pause;
    return 0;
}
