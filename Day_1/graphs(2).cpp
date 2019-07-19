#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
int const maxn = 2000 + 10;
int e[maxn], sum = 1;

void dfs(int v)
{
    if (e[v] != 0)
    {
        sum++;
        dfs(e[v]);
    }
}

int main(void)
{
    FAST_IO;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a != -1)
            e[i] = a;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = 1;
        dfs(i);
        ans = max(sum, ans);
    }
    cout << ans << endl;

    // system("pause");
    return 0;
}