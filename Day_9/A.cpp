#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1000000 + 10;
int a[maxn], b[maxn], Next[maxn];
int n, m;

void getNext() {
    memset(Next, 0, sizeof(Next));
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < m) {
        if (j == -1 || b[i] == b[j]) {
            i++;
            j++;
            Next[i] = j;
        } else {
            j = Next[j];
        }
    }
}

int firstKmp() {
    int i = 0, j = 0;
    while (i < n) {
        if (j == -1 || a[i] == b[j]) {
            i++;
            j++;
            if (j == m) {
                return i - j;
            }
        } else {
            j = Next[j];
        }
    }
    return -1;
}

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        getNext();
        int ans = firstKmp();
        if (ans != -1){
            cout << ans + 1 << endl;
        } else {
            cout << ans << endl;
        }
    }

    // PAUSE;
    return 0;
}