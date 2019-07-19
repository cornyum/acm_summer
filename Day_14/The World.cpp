#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
map<char, int> mp;

int main(void) {
    // FAST_IO;
    int t;
    mp.insert({'B', 8});
    mp.insert({'W', -5});
    mp.insert({'L', 0});
    mp.insert({'M', 3});
    // cin >> t;
    scanf("%d", &t);
    while (t--) {
        char cc[10],city1[10], city2[10];
        int h, m;
        scanf("%d:%d %s", &h, &m, cc);
        scanf("%s %s", city1, city2);
        int new_h = h -mp[city1[0]] + mp[city2[0]];
        int uct = h -mp[city1[0]];
        if (uct == 12 && !strcmp("AM", cc)) {
            printf("%s %d:%d", mp[city2[0]]);
        }
    }
    pause;
    return 0;
}