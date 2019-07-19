#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 1e3 + 10;
int a[maxn];
int n;

int main(void) {
    FAST_IO;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = a[i - 1] + a[i];
    }
    

    system("pause");
    return 0;
}