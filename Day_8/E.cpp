#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 110;
int const INF = 0x3f;
int dis[maxn][maxn];
int a[maxn];
struct node {
    int x, y;
    node(const int &x = 0, const int &y = 0) : 
        x(x), y(y) {}
}v[maxn];

int distance(node &x, node &y) {
    return abs(x.x - y.x) + abs(y.y - x.y);
}

void flody(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}

int main(void) {
    FAST_IO;
    memset(dis, INF, sizeof(dis));
    int d, n;
    cin >> n >> d;
    // a[1] = 1;
    for (int i = 2; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        dis[i][i] = 0;
        cin >> v[i].x >> v[i].y;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                dis[i][j] = d * distance(v[i], v[j]) - a[i];
            }
        }
    }
    flody(n);
    cout << dis[1][n] << endl;

    // PAUSE;
    return 0;
}