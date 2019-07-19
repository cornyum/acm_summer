#include <iostream>
#include <cstring>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;

int const maxn = 10000 + 10;
char s[maxn << 1];

int get_min(char *s, size_t len) {
    int i = 0, j = 1, k = 0;
    while (i < len && j < len) {
        for (k = 0; k < len; k++) {
            if (s[i + k] != s[j + k]) {
                break;
            }
        }
        if (k == len)
            break;
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
    int t;

    cin >> t;
    while (t--) {
        cin >> s;
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            s[len + i] = s[i];
        }
        cout << get_min(s, len) + 1<< endl;
    }
    
    // PAUSE;
    return 0;
}