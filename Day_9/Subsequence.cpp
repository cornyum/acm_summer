#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
int const maxn = 100000 + 10;
char s[maxn], p[maxn];
int now[maxn], Next[maxn][30];

void init(){
    int len = strlen(s);
    memset(now, -1, sizeof(now));
    for (int i = len - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            Next[i][j] = now[j];
        }
        now[s[i] - 'a'] = i;
    }
}


int main(void) {
    scanf("%s", s);
    init();
    int n;
    scanf("%d", &n);
    while (n--){
        scanf("%s", p);
        int x = now[p[0] - 'a'];
        if (x == -1){
            puts("NO");
        } else {
            int flag = 0;
            int len = strlen(p);
            for (int i = 1; i < len; i++) {
                if (Next[x][p[i] - 'a'] == -1) {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                puts("NO");
            } else {
                puts("YES");
            }
        }
    }

    // PAUSE;
    return 0;
}