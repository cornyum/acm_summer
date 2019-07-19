#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
const int maxn = (1000 + 10) << 1;
int father[maxn];
vector<int> e[maxn];
int a[maxn];
char mp[maxn][maxn];
int n, m, cnt;
int inedge[maxn];
int flag = 0;
 
void init(){
    for (int i = 0; i < maxn; i++){
        father[i] = i;
    }
}
 
int find(int x){
    return x == father[x] ? x : father[x] = find(father[x]);
}
 
void unio(int x, int y){
    int a = find(x), b = find(y);
    if (a != b){
        father[a] = b;
    }
}
 
void toposort(){
    queue<int> q;
    for (int i = 1; i <= n + m; i++){
        if (find(i) == i && inedge[i] == 0){
            q.push(i);
        }
    }
    int v = 0;
    while (!q.empty()){
        int qs = q.size();
        v++;
        while (qs--){
            int x = q.front();
            q.pop();
            cnt--;
            a[x] = v;
            for (auto &u : e[x]){
                if (--inedge[u] == 0){
                    q.push(u);
                }
            }
        }
    }
    if (cnt){
        flag = 1;
    }
}
 
int main(void){
    FAST_IO;
    cin >> n >> m;
    flag = 0;
    init();
    int num = n + m;
    for (int i = 1; i < n + 1; i++)
        cin >> (mp[i] + 1);
    for (int i = 1; i < n + 1 ;i++){
        for (int j = 1; j < m + 1; j++){
            if (mp[i][j] == '='){
                unio(i, n + j);
                num--;
            }
        }
    }
    cnt = num;
    for (int i = 1; i < n + 1; i++){
        for (int j = 1; j < m + 1; j++){
            if (mp[i][j] == '=')
                continue;
            if (find(i) == find(n + j)){
                flag = 1;
                break;
            }
            if (mp[i][j] == '<'){
                e[find(i)].push_back(find(n + j));
                inedge[find(n + j)]++;
            } else {
                e[find(n + j)].push_back(find(i));
                inedge[find(i)]++;
            }
        }
        if (flag) {
            break;
        }
    }
    toposort();
    if (flag) {
        cout << "NO" <<  endl;
    } else {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++){
            if (i != 1) cout << ' ';
            cout << a[find(i)];
        }
        cout << endl;
        for (int i = 1; i <= m; i++){
            if (i != 1) cout << ' ';
            cout << a[find(i + n)];
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}