#include<bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 1e5 + 10;
ll a[maxn];
int const INF = 0x3f3f3f3f;
int main(){
    int n;
    cin >> n;
    ll x,y,z;
    cin >> x >> y >>z;
    ll mx = -0x3f3f3f3f, mn = 0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        ll s;
        cin >> s;
        mx=max(mx,s);
        mn=min(mn,s);
    }
    long long sx,sy,sz;
    if(x>=0) sx=x*mx;
    else sx=x*mn;
    if(y>=0) sy=y*mx;
    else sy=y*mn;
    if(z>=0) sz=z*mx;
    else sz=z*mn;
    cout << sx+sz+sy << endl;
    // pause;
    return 0;
}