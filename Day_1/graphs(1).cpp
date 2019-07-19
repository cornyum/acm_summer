#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
int const maxn = 1e5 + 10;
int e[maxn];
int main(void){
    FAST_IO;
    int n, m;
    cin >> n >> m;
    int f1 = 1, f2 = 1, f3 = 1;
    
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a]++;
        e[b]++;
    }
    int a = 0, b = 0, c = 0;
    for (int i = 1; i <= n; i++)
    {
        if (e[i] == 1)
            a++;
        if (e[i] == 2)
            b++;
        if (e[i] == n - 1) c++;
    }
    if (c == 1 && a == n -1)
        cout << "star topology" << endl;
    else if (a == 2 && b == n - 2)
        cout << "bus topology" << endl;
    else if (b == n)
        cout << "ring topology" << endl;
    else 
        cout << "unknown topology" << endl;

    // system("pause");
    return 0;
}