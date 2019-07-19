// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdio>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1000000 + 10;
char s[maxn], new_string[maxn << 1];
int p[maxn << 1];

int init() {
    memset(p, 0, sizeof(p));
    int len = strlen(s);
    new_string[0] = '$';
    new_string[1] = '#';
    int j = 2;
    for (int i = 0; i < len; i++) {
        new_string[j++] = s[i];
        new_string[j++] = '#';
    }
    new_string[j] = '\0';
    return j;
}

int Manacher() {
    int len = init();
    int max_len = -1;
    int id;
    int mx = 0;
    for (int i = 1; i < len; i++) {
        if (i < mx) {
            p[i] = min(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }
        while (new_string[i - p[i]] == new_string[i + p[i]]) {
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
    int n = 0;
    while (cin >> s) {
        if (!strcmp("END", s))
            break;
        cout << "Case " << ++n << ": " << Manacher() << endl;
    }

    // PAUSE;
    return 0;
}