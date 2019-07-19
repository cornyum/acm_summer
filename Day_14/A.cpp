#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
int const maxn = 1000000 + 10;
int a[maxn];

int main(void) {
    FAST_IO;
    for (int i = 1; i < maxn; i++) {
        a[i] += a[i - 1];
        string s = to_string(i);
        if (s.find("4") != string::npos || s.find("62") != string::npos)
            a[i]++;
    }
    int x, y;
    while (cin >> x >> y) {
        if (x == 0 && y == 0) break;
        cout << (y - x + 1) - (a[y] - a[x - 1]) << endl;
    }
    // pause;
    return 0;
}