#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause");
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int main(void) {
    FAST_IO;
    ll a, b;
    while (cin >>a >> b) {
        ll s = a + b;
        cout << ((s & 1) ? s +1 : s ) << endl;
    }    

    // pause;
    return 0;
}