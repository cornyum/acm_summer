#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 2e6 + 10;
char s1[maxn], s2[maxn], new_str[maxn << 1];
ll p[maxn << 1];

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

ll manacher() {
    int len = init();
    ll mx = 0, id = 0;
    ll ans = 0;
    for (int i = 1; i < len; i++) {
        if (i < mx) {
            p[i] = min(p[2 * id - i], (ll)(mx - i));
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
        if (new_str[i] == '#')
            ans += (p[i] - 1) / 2;
        else 
            ans += p[i] / 2;
    }
    return ans;
}

int main(void) {
    int t;

    scanf("%d", &t);
    while (t--) {
        scanf("%s %s", s1, s2);
        if (0 != strcmp(s1, s2)) {
            int flag = 0, len = strlen(s1);
            int l = -1, r = -1;
            for (int i = 0; i < len; i++) {
                if (s1[i] != s2[i] && !flag) {
                    flag = 1;
                    l = i;
                } else if (s1[i] != s2[i]){
                    r = i;
                }
            }
            if (l == -1 || r == -1) {
                puts("0");
                continue;
            }
            flag = 0;
            ll ans = 0;
            int llen = r - l + 1;
            for (int i = 0; i < llen; i++) {
                if (s1[l + i] != s2[r - i])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) {
                puts("0");
                continue;
            } else {
                l--;
                r++;
                ans = 1;
                while (l >= 0 && r < len) {
                    if (s1[l] != s2[r])
                        break;
                    ans++;
                    l--;
                    r++;
                }
            }
            printf("%lld\n", ans);
        } else {
            printf("%lld\n", manacher());
        }
    }
    return 0;
}