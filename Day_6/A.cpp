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
int const maxn = 12;
int a[maxn][maxn];

int main(void) {
    // FAST_IO;
    int n;
    while (scanf("%d", &n) != EOF)
    {
        memset(a, 0, sizeof(a));
        int c = 0;
        for (int i = 1; i <= n; i++)
            a[1][i] = ++c;
        for (int i = 2; i <= n; i++)
            a[i][n] = ++c;
        for (int i = n - 1; i >= 1; i--)
            a[n][i] = ++c;
        for (int i = n - 1; i >= 2; i--)
            a[i][1] = ++c;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i][j] != 0)
                    printf("%3d", a[i][j]);
                else {
                    printf("   ");
                }
            }
            printf("\n");
        }
    }
    
    

    // system("pause");
    return 0;
}