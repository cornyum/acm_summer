#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
using namespace std;

int const maxn = 1e3 + 10;
char s[maxn];

int get_min(char *s, size_t len) {
    int i = 0, j = 1, k = 0;
    while (i < len && j < len) {
        for (k = 0; k < len; k++) {
            if (s[i + k] != s[j + k]) {
                break;
            }
        }
        if (k == len) break;
        if (s[i + k] > s[j + k]) {
            i = i + k + 1;
            if (j == i) 
                i++;
        } else {
            j = j + k + 1;
            if (i == j) 
                j++;
        }
    }

    return min(i, j);
}

int main(void) {
    FAST_IO;

    cin >> s;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        s[len + i] = s[i];
    }
    int ans = get_min(s, len);
    cout << ans << endl;
    for (int i = ans; i < ans + len; i++) {
        cout << s[i];
    }
    cout << endl;

    PAUSE;
    return 0;
}