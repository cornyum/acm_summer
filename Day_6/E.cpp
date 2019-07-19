#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cctype>

#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1000 + 10;
struct node {
    int u, v;
    node(const int &u = 0, const int &v = 0) : u(u), v(v) {}
};
vector<node> e;
int vis[maxn];
int father[maxn], n, in[maxn];
int cnt = 0;
void init() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}

int find(int x) {
    return father[x] == x ?x : father[x] = find(father[x]);
}

void unio(int u, int v) {
    int x = find(u), y = find(v);
    if (x != y) {
        father[x] = y;
    }
}

int main(void) {
    FAST_IO;
    cin >> n;

    init();

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        e.push_back(node(u, v));
        int x = find(u), y = find(v);
        if (x != y) {
            father[x] = y;
        } else {
            vis[i] = 1;
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 1; i < n; i++) {
        if (vis[i]) {
            int u = e[i - 1].u, v = e[i - 1].v;
            for (int j = 2; j <= n; j++) {
                if (find(j) != find(1)){
                    unio(j, 1);
                    cout << u << " " << v << " " << j << " " << 1 << endl;
                    break;
                }
            }
        }
    }

    // system("pause");
    return 0;
}

/*
8
1 2
1 3
1 4
2 4
3 4
3 5
4 5

5
1 2
1 3
2 3
2 4

39
6 13
15 39
10 35
31 28
4 21
12 39
3 7
3 13
6 1
5 14
36 28
12 15
18 38
30 29
19 34
36 16
20 22
8 13
38 32
26 39
21 37
1 7
15 27
12 26
8 3
6 14
29 2
25 23
32 21
5 16
32 25
6 8
13 10
23 30
34 37
29 33
28 14
36 5
 */