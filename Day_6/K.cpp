#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int main(void) {
    FAST_IO;
    string a, b;
    cin >> a >> b;
    sort(a.begin(), a.end());
    if (a.length() < b.length()) {
        reverse(a.begin(), a.end());
        cout << a << endl;
    } else {
        for (int i = 0; i < a.length(); i++) {
            for (int j = a.length() - 1; j > i; j--) {
                string t = a;
                swap(a[i], a[j]);
                sort(a.begin() + i + 1, a.end());
                if (a > b) {
                    a = t;
                } else {
                    break;
                }
            }
        }
        cout << a << endl;
    }

    // system("pause");
    return 0;
}