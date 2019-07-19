#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;

int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    int c = 0;
    while (t--) {
        int n;
        cin >> n;
        int x = sqrt(n);
        cout << "Case " << ++c << ": ";
        if (x & 1) {
            cout << "odd" << endl;
        } else {
            cout << "even" << endl;
        }
    }
    // system("pause");
    return 0;
}