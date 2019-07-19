#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause");
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1e3 + 10;
int a[maxn];
int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0 ; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        int d = a[1] - a[0];
        int f = 0;
        for (int i = 1 ; i < n - 1; i++) {
            if (a[i + 1] - a[i] != d){
                f = 1;
                break;
            }
        }
        if (f) 
            cout << "no" <<endl;
        else cout << "yes" << endl;
    }

    // pause;
    return 0;
}