// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 150000 + 10;
int a[maxn];
int dp[maxn][2];

int main(void) {
    FAST_IO;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] - a[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] + a[i]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
    // pause;
    return 0;
}