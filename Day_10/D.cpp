// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cctype>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1e7 + 10;
int trie[maxn][28], tot = 1, cnt[maxn];
char str[1100][23];
char t[28];
int tlen = 0;

void insert(char *str) {
    int len = strlen(str), p = 1;
    for (int i = 0; i < len; i++) {
        int k = str[i] - 'a';
        if (trie[p][k] == 0) 
            trie[p][k] = ++tot;
        p = trie[p][k];
        cnt[p]++;
    }
}

void search(char *str) {
    memset(t, 0, sizeof(t));
    tlen = 0;
    int len = strlen(str), p = 1;
    for (int i = 0; i < len; i++) {
        p = trie[p][str[i] - 'a'];
        t[tlen++] = str[i];
        if (cnt[p] == 1) {
            return;
        }
    }
    
}

int main(void) {
    FAST_IO;
    int line = 0;
    while (cin >> str[line]) {
        insert(str[line]);
        ++line;
    }

    for (int i = 0; i < line; i++) {
        search(str[i]);
        cout << str[i] << " " << t << endl;
    }

    PAUSE;
    return 0;
}