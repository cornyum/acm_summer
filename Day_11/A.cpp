#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
using namespace std;
int const maxn = 110000 + 10;
char s1[maxn], new_str[maxn << 1];
int p[maxn << 1];

int init() {
    int len = strlen(s1);
    new_str[0] = '$';
    new_str[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++) {
        new_str[j++] = s1[i];
        new_str[j++] = '#';
    }
    new_str[j] = '\0';
    return j;
}

int manacher() {
    int len = init(), max_len = -1, mx = 0, id = 0;
    for (int i = 1; i < len; i++) {
        if (i < mx) {
            p[i] = min(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }
        while (new_str[i - p[i]] == new_str[i + p[i]]) {
            p[i]++;
        }
        if (mx < i + p[i]) {
            id = i;
            mx = i + p[i];
        }
        max_len = max(max_len, p[i] - 1);
    }
    return max_len;
}

int main(void) {
    FAST_IO;
    while (cin >> s1) {
        cout << manacher() << endl;
    }
    PAUSE;
    return 0;
}