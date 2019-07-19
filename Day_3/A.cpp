#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
int const maxn = 5e5 + 10;
int father[maxn], n, m;
int a[maxn];

void init(void){
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
}

int find(int x){
    return x == father[x] ? x : father[x] = find(father[x]);
}

void unio(int x, int y){
    int a = find(x), b = find(y);
    if(a != b){
        father[b] = a;
    }
}

int main(void){
    FAST_IO;
    cin >> n >> m;
    init();
    
    for (int i = 1; i <= m; i++){
        int q;
        cin >> q;
        if (!q) continue;
        int a, b;
        cin >> a;
        for (int j = 1; j < q; j++){
            cin >> b;
            unio(a, b);
        }
    }

    for (int i = 1; i <= n; i++){
        a[find(i)]++;
    }
    for (int i = 1; i <= n; i++){
        cout << a[find(i)];
        if (i != n) cout << ' ';
    }
    cout << endl;

    // system("pause");
    return 0;
}