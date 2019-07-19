#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define PAUSE system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1000 + 10;
int const maxm = 1000 + 10;

char Find[maxm],a[maxn];
int Next[maxm];

void getNext(int len) {
    // memset(Next, 0, sizeof(Next));
    int i = 0;
    int j = -1;
    Next[0] = -1;
    while (i < len) {
        if (j == -1 || Find[i] == Find[j]) {
            i++;
            j++;
            Next[i] = j;
        } else {
            j = Next[j];
        }
    }
}

int KMP(int lena, int lenb) {
    getNext(lenb);
    int i = 0, j = 0;
    int ans = 0;
    while (i < lena) {
        if (j == -1 || a[i] == Find[j]) {
            i++;
            j++;
            if (j == lenb) {
                ans++;
                j = Next[i];
            }
        } else {
            j = Next[j];
        }
    }
    return ans;
}

int main(void) {
    FAST_IO;
    
    while (cin >> a){
        if (a[0] == '#')
            break;
        cin >> Find;
        cout << KMP(strlen(a), strlen(Find)) << endl;
    }

    PAUSE;
    return 0;
}