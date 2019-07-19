#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 1500 + 10;
int prime=233317; 
ull mod=1e9 + 7;
ull base=131;
char str[maxn];
UINT Hash[maxn];
UINT a[10000 + 10];

void myHash(int len) {
    Hash[0] = 0;
    for (int i = 1; i <= len; i++) {
        Hash[i] = (Hash[i - 1] * base + str[i - 1]) % mod;
    }
} 

UINT BKDRHash(const char *s) {
    UINT seed = 131;
    UINT hash = 0;
    while (*s) {
        hash = hash * seed + (*s++);
    }
    return hash & 0x7FFFFFFF;
}

int main(void) {
	FAST_IO;
	int n;
	cin >> n;
	for (int i = 0; i < n;  i++) {
		cin >> str;
        a[i] = BKDRHash(str);
	}
    sort(a, a + n);
    cout << unique(a, a + n) - a << endl;
	// pause;	
	return 0;
}
