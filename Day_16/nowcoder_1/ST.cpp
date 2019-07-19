#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1e5 +10;
int a[maxn];
int st[maxn][20];

void init(int n) {
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; (1 << j) - 1 < n; j++) {
        for (int i = 0; i + (1 << j) - 1 < n; i++) {
            st[i][j] = min(st[i][j - 1],st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int search(int l, int r) {
    int k = log2(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}



int main(void) {


    return 0;
}