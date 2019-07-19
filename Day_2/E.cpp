#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
int const maxn = 500 * 2;
vector<int> e[maxn], ans;
int inedage[maxn], n, m;

void toposort(){
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++){
        if (!inedage[i]) q.push(i);
    }
    while (!q.empty()){
        int x = q.top();
        q.pop();
        ans.push_back(x);
        for (int &u : e[x]){
            if (--inedage[u] == 0){
                q.push(u);
            }
        }
    }
}

int main(void){
    FAST_IO;
    while (cin >> n >> m){
        memset(inedage, 0, sizeof(inedage));
        ans.clear();
        memset(e, 0, sizeof(e));
        for (int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            inedage[v]++;
            e[u].push_back(v);
        }
        toposort();
        for (int i = 0; i < ans.size(); i++)
        {
            if (i != 0) cout << " " << ans[i];
            else cout << ans[i];
        }
        cout << endl;
    }

    // system("pause");
    return 0;
}