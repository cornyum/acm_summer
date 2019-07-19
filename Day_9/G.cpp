#include <bits/stdc++.h>
#define PAUSE system("pause")
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 100000 + 10;
int a[maxn];
char ans[maxn];
int temp[30];
int main(void) {
    FAST_IO;

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ans[1] = 'a';
    int x = 0;
    for (int i = 2; i <= n; i++) {
        if (a[i] != i) {
            ans[i] = ans[(i - 1) % a[i] + 1];
        } else {
            x++;
            int last = i - 1;
            while (a[last] != last) {
                last = (last - 1) % a[last] + 1;
                temp[ans[last + 1] - 'a'] = x;
            }
            for (int j = 1; j < 26; j++) {
                if (temp[j] != x){
                    ans[i] = j + 'a';
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << endl;

    // PAUSE;
    return 0;
}