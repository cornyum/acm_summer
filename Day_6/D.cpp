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
int a[15];
int dp[100000 + 10];

void init() {
    dp[1] = 1;
    for (int i = 2; i <= 100000; i++){
        int x = i;
        memset(a, 0, sizeof(a));
        int f = 0;
        while (x) {
            int t = x % 10;
            if (!a[t]){
                a[t] = 1;
            } else {
                f = 1;
                break;
            }
            x /= 10;
        }
        dp[i] = dp[i - 1] + !f;
    }
}

int main(void) {
    // FAST_IO;
    int t;
    // cin >> t;
    init();
    scanf("%d", &t);
    while(t--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", dp[r] - dp[l - 1]);
    }

    // system("pause");
    return 0;
}