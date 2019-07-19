#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
int const maxn = (1000000 + 10) * 4;
int a[maxn], father[maxn], n, m;

void init(){
    for (int i = 1; i <= m; i++)
        father[i] = i;
}

int find(int x){
    return x == father[x] ? x : father[x] = find(father[x]);
}

void unio(int x, int y){
    int fa = find(x), fb = find(y);
    if(fa != fb){
        father[fa] = fb;
    }
}
int query(int x) {
    return lower_bound(a, a + m, x) - a + 1;
}

struct node {
    int a, b, opt;
    bool operator<(const node &p) const {
        return opt > p.opt;
    }
}d[maxn];

int main(void){
    FAST_IO;
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> d[i].a >> d[i].b >> d[i].opt;
            a[cnt++] = d[i].a;
            a[cnt++] = d[i].b;
        }
        sort(a, a + cnt);
        m = unique(a, a + cnt) - a;
        init();
        int f = 1;
        sort(d, d + n);
        for (int i = 0; i < n; i++)
        {
            int u = query(d[i].a);
            int v = query(d[i].b);
            if (d[i].opt){
                unio(u, v);
            } else {
                if (find(u) == find(v)){
                    f = 0;
                }
            }
        }
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    // system("pause");
    return 0;
}
/*
100
4
24 35 1
31 35 1
31 20 1
20 24 0
2
1 2 1
1 2 0
2
1 2 1
2 1 1
 */