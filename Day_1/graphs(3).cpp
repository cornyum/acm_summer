#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;

int main(void)
{
    FAST_IO;
    ll n, m;
    cin >> n >> m;
    if (m * 2 >= n)
        cout << 0 << " ";
    else 
        cout << n - m * 2 << " ";
    ll ans = n;
    for (ll i = n; i >= 0; --i)
    {
        if (i * i - i < 2 * m)
            break;
        ans = i;
    }
    cout << n - ans << endl;
    
    // system("pause");
    return 0;
}