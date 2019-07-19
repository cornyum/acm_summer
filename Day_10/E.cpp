#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
int const maxn = 1e7 + 10;
int trie[maxn][3], tot = 1;
UINT value[maxn];

void insert(int a[], UINT x) {
    int p = 1;
    for (int i = 0; i <= 32; i++) {
        if (!trie[p][a[i]]) {
            trie[p][a[i]] = ++tot;
        }
        p = trie[p][a[i]];
    }
    value[p] = x;
}

int search(int a[]) {
    int p = 1;
    for (int i = 0; i <= 32; i++) {
        if (trie[p][a[i] ^ 1]) {
            p = trie[p][a[i] ^ 1];
        } else {
            p = trie[p][a[i]];
        }
    }
    return value[p];
}

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        int bits[34];
        memset(trie, 0, sizeof(trie));
        tot = 1;
        int n, m;
        cin >> n >> m;
        while (n--) {
            UINT x, y;
            cin >> x;
            y = x;
            for (int i = 32; i >= 0; i--) {
                bits[i] = x % 2;
                x /= 2;
            }
            insert(bits, y);
        }
        cout << "Case #" << ++c << ":" << endl;
        for (int i = 0; i < m; i++) {
            UINT x;
            cin >> x;
            for (int j = 32; j >= 0; j--) {
                bits[j] = x % 2;
                x /= 2;
            }
            cout<< search(bits) << endl;
        }
    }

    // PAUSE;
    return 0;
}