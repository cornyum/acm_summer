#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>
#include <cmath>
#include <cctype>

#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 65000 + 10;
char a[maxn];

int main(void) {
    FAST_IO;
    int n;
    cin >> n;
    cin >> (a + 1);
    // sort(a + 1, a + 1 + n);
    ll ans = 0;
    for (int i = 1; i <= n; i++){
        if ((a[i]-48) % 2 == 0) {
            ans += i;
        }
    }
    cout << ans << endl;
    // system("pause");
    return 0;
}