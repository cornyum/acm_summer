#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
struct node {
    int v, next;
    node(const int &v = 0, const int &next = 0) : v(v), next(next) {}
}e[maxm];
int const maxn = 3000 + 2;
int const maxm = maxn * maxn;
int cnt = 1, head[maxn];

void add(int u, int v){
    e[cnt].v = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}



int main(void){
    FAST_IO;
    int n, m;

    cin >> n >> m;

    system("pause");
    return 0;
}
