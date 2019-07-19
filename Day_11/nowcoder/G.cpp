#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
double const PI = acos(-1);

int main(void) {
    FAST_IO;
    double n;
    // cin >> n;
    scanf("%lf", &n);
    double r = n / PI;
    printf("%.3f\n", r * r * PI / 2);
    
    // system("pause");
    return 0;
}