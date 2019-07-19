#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
const int maxn = 1000000 + 10;
char a[maxn];
int Next[maxn];

void getNext(int len) {
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < len) {
        if (j == -1 || a[i] == a[j]) {
            i++;
            j++;
            Next[i] = j;
        } else {
            j = Next[j];
        }
    }
}

int main(void) {
    FAST_IO;
    int t = 0;
    int n;
    while (cin >> n && n != 0) {
        cin >> a;
        cout << "Test case #" << ++t << endl;
        getNext(n);
        for (int i = 2; i <= n; i++) {
            if (i % (i - Next[i]) == 0 && i / (i - Next[i]) > 1) {
                cout << i << " " << i / (i - Next[i]) << endl;
            }
        }
        cout << endl;
    }

    // PAUSE;
    return 0;
}