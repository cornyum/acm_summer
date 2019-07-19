// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 3000 + 10;

char a[maxn], b[maxn];

string dfs(char *s, int l, int r) {
    int cnt = 0, p = l;
    vector<string> temp;
    for (int i = l; i <= r; i++) {
        if(s[i] == '0') {
            cnt++;
        } else {
            cnt--;
        }
        if (cnt == 0) {
            temp.push_back(dfs(s, p + 1, i - 1));
            p = i + 1;
        }
    }
    sort(temp.begin(), temp.end());
    string ret = "0";
    for (int i = 0u; i < temp.size(); i++) {
        ret += temp[i];
    }
    return ret + "1";
}

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        if (dfs(a, 0, strlen(a) - 1) == dfs(b, 0, strlen(b) - 1)) {
            cout << "same" << endl;
        } else {
            cout << "different" << endl;
        }
    }

    // PAUSE;
    return 0;
}