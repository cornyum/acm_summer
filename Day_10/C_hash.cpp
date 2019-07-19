#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
ll const base = 131;
ll const MOD = 1e9 + 9;
int const maxn = 1e5 + 10;
char str[30];
map<ll, ll> hashcnt;

ll Hash(ll has[], const char *str, int f) {
    has[0] = 1;
    int len = strlen(str);
    for (int i = 1; i <= len; i++) {
        has[i] = (has[i - 1] * base + str[i - 1]) % MOD;
        if (!f) ++hashcnt[has[i]];
    }
    return has[len];
}

int main(void) {
    FAST_IO;
    int line = 0;
    char s[30];
    ll shas[30];
    while (cin.getline(str, 30)) {
        if (strcmp("", str) == 0) 
            break;
        Hash(shas, str, 0);
    }
    while (cin >> s) {
        ll h = Hash(shas, s, 1);
        cout << hashcnt[h] << endl;
    }
    // system("pause");
    return 0;
}