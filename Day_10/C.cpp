#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1e7 + 10;
int trie[maxn][28], tot = 1;
int cnt[maxn];

void insert(char *str) {
    int len = strlen(str), p = 1;
    for (int i = 0; i < len; i++) {
        int k = str[i] - 'a';
        if (trie[p][k] == 0) trie[p][k] = ++tot;
        p = trie[p][k];
        cnt[p]++;
    }
}

int search(char *str) {
    int ans = 0;
    int len = strlen(str), p = 1;
    for (int i = 0; i < len; i++) {
        p = trie[p][str[i] - 'a'];
        ans = cnt[p];
    }
    return ans;
}

int main(void) {
    FAST_IO;
    char s[30];
    while (cin.getline(s, maxn)) {
        if(!strcmp("", s)) {
            break;
        }
        insert(s);
    }

    while (cin >> s) {
        cout << search(s) << endl;
    }

    PAUSE;
    return 0;
}
