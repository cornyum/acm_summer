#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause");
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int s[5];
int main(void) {
    FAST_IO;
    int t;
    cin >> t;
    while (t--) {
        ll a, b, c;
        int flag=0;
        cin >> a >> b >> c;
        memset(s,0,sizeof(s));
        if(a>=1) s[1]=1;
        if(a>=2 || b>=1) s[2]=1;
        if(a>=1 && b>=1 || a>=3) s[3]=1;
        if(a>=4 || b>=2 || a>=2 && b>=1) s[4]=1;
        for(int i=1;i<=4;i++){
            if(s[i]==0){
                cout << i << endl;
                flag=1;
                break;
            }
        }
        if(flag==0) cout << a+b*2+c*5+1 << endl;
    }
    // pause;
    return 0;
}