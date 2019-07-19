#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
int const maxn = 10000 + 10;
int father[maxn], n, m;
typedef pair<int ,int> pint;

void init(void){
    for (int i = 0; i <= n; i++){
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
pint a[100000 + 10];
int s[100000 + 10];


int main(void){
    FAST_IO;
    while (cin >> n >> m){
        memset(s, 0, sizeof(s));
        init();
        for (int i = 0; i < m; i++){
            cin >> a[i].first >> a[i].second;
        }
        s[m - 1] = n;
        for (int i = m - 1; i >= 0; i--){
            int x = find(a[i].first);
            int y = find(a[i].second);
            if (x != y){
                father[x] = y;
                s[i - 1] = s[i] - 1;
            } else {
                s[i - 1] = s[i];
            }
        }
        for (int i = 0; i < m; i++){
            cout << s[i] << endl;
        }
    }

    system("pause");
    return 0;
}