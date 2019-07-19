#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;

int main(void) {
    FAST_IO;
    int n;
    cin >> n;
    int x = n % 4;
    if (x == 1) {
        cout << 0 << " A" << endl;
    } else if(x == 2) {
        cout << 1 << " B" << endl;
    } else if (x == 3) {
        cout << 2 << " A" << endl;
    } else {
        cout << 1 << " A" << endl;
    }

    // pause;
    return 0;
}