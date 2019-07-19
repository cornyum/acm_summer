#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause");
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;

int main(void) {
    FAST_IO;
    string s;
    cin >> s;

    int len = s.length() / 2;
    if ((s.length() & 1) && s.length() != 1) {
        s[len] = '0';
    }
    if (s.length() == 2 && s != "99") {
        if (s[0] != s[1]) {
            if(s[0] > s[1]) {
                s[1] = s[0];
            } else {
                s[0] = s[1];
            }
        } else {
            s[0]++;
            s[1]++;
        }
    } else {
        for (int i = len - 1; i >= 0; i--) {
            
        }
    }
    // cout << s <<endl;
    pause;
    return 0;
}