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
int a[10][10];
int main(void) {
    FAST_IO;
    int s, e;
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1)
            {
                s = i;
                e = j;
            }
        }
    }
    cout << abs(3 - s) + abs(3 - e) <<endl;

    // pause;
    return 0;
}
