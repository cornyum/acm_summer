#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <memory>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 1e5 + 10;
ll a[maxn];
int const INF = 0x3f3f3f3f;

int main(void) {
    FAST_IO;
    ll n, p[5];
    ll mx = -0x3f3f3f3f, mi = 0x3f3f3f3f;
    ll mxnn = -0x3f3f3f3f, minn = 0x3f3f3f3f;
    cin >> n >> p[0] >> p[1] >>p[2];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] > 0){
            mx = max(mx, a[i]);
        }
        mxnn = max(mxnn, a[i]);
        if (a[i] < 0) {
            mi = min(mi, a[i]);
        }
        minn = min(minn, a[i]);
    }
    ll sum = 0;
    for (int i = 0; i < 3; i++) {
        if (p[i] > 0) {
            if (mx != -INF) {
                sum += mx * p[i];
            } else {
                sum += p[i] * mxnn;
            }
        } else {
            if (mi != INF) {
                sum += p[i] * mi;
            } else sum += p[i] * minn;
        }
    }
    
    cout << sum << endl;
    pause;
    return 0;
}
