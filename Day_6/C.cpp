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
ll const maxn = 1e9;
int main(void) {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
    } else {
        cout << n  << " "<< n + 1 << " "<<(n) *(n + 1) << endl;
    }

    system("pause");
    return 0;
}