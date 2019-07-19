#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
int const maxn = 1000;
int n, m;
int father[maxn];
struct node{
    int u, v, w;
    bool operator<(const node & p) const {
        return w < p.w;
    }
};
node e[maxn];
void init(){
    for (int i = 1; i <= m; i++){
        father[i] = i;
    }
}

int find(int x){
    return x == father[x] ? x : father[x] = find(father[x]);
}

int Kruskal(){
    int ans = 0;
    int cnt = m;
    sort(e, e + n);
    for (int i = 0; i < n; i++){
        int x = e[i].u;
        int y = e[i].v;
        int a = find(x),b = find(y);
        if (a != b) {
            ans += e[i].w;
            father[b] = a;
            cnt--;
        }
    }
    // cout << cnt << endl;
    if (cnt == 1)
        return ans;
    return 0;
}

int main(void){
    while (cin >> n >> m && n != 0){
        init();
        for (int i = 0; i < n; i++)
        {
            cin >> e[i].u >> e[i].v >> e[i].w;
        }
        int ans = Kruskal();
        if (ans) cout << ans << endl;
        else cout << "?" << endl;
    }

    // system("pause");
    return 0;
}