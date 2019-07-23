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
int const maxn = 100;
vector<int> e[maxn];
int indege[maxn],in[maxn];

bool toposort(int n) {
    int cnt = 0;
    queue<int> q;
    memcpy(in, indege, sizeof(in));
    for (int i = 1; i <= n; i++) {
        if (!in[i])
            q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cnt++;
        for (auto &u : e[x]) {
            if (--in[u] == 0) 
                q.push(u);
        }
    }
    if (cnt == n)
        return true;
    return false;
}

int main(void) {
    FAST_IO;
    int n;
    while (cin >> n) {
        memset(indege, 0, sizeof(indege));
        memset(e, 0, sizeof(e));
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
            e[u].push_back(v);
            indege[v]++;
            if (!flag && !toposort(cnt)) {
                flag = 1;
                cout << a << " " << b << endl;
            }
        }
        if (!flag) {
            cout << 0 << endl;
        }
    }
    // pause;
    return 0;
}