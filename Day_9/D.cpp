#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 100000  + 10;
int const maxm = 1000 + 10;

char Find[maxn];
int Next[maxn];

void getNext(int len) {
    int i = 0, j = -1;
    Next[0] = -1;
    while (i < len) {
        if (j == -1 || Find[i] == Find[j]) {
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
    int t;
    cin >> t;

    while (t--) {
        cin >> Find;
        int len = strlen(Find);
        getNext(len);
        int clen = len - Next[len];
        if (clen != len && len % clen == 0)
            cout << 0 << endl;
        else 
            cout << clen - Next[len] % clen << endl;
    }

    // PAUSE;
    return 0;
}