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
string s[53];
int const INF = 0x3f3f3f3f;

int main(void) {
    FAST_IO;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int mi = INF;
    int len = s[0].length();
    int flag = 0;
    for (int i = 0; i < n; i++) {
        string t = s[i] + s[i];
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            auto x1 = t.rfind(s[j]);
            auto x2 = t.find(s[j]);
            if (x2 == string::npos && x1 == string::npos) {
                flag = 1;
                break;
            } else if (x2 == 0) {
                continue;
            }
            sum += len - x1;
        }
        if(flag) break;
        mi = min(sum, mi);
    }
    if (flag)
        cout << -1 << endl;
    else 
        cout << mi << endl;
    // pause;
    return 0;
}
