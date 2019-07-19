#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause");
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;

int main(void) {
    FAST_IO;
    for (int i = 1; i <= 50; i++) {
        cout << i << " " << fixed << setprecision(18) <<(double)1/i << endl;
    }
    pause;
    return 0;
}