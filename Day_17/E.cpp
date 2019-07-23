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
int fa[200];
void init(){
    for(int i=1;i<=200;i++) fa[i]=i;
}
int get(int x){
    if(x==fa[x]) return x;
    return fa[x]=get(fa[x]);
}
int mergr(int x,int y){
    int a,b;
    a=get(x);
    b=get(y);
    if(a==b) return 1;
    else{
        fa[b]=fa[a];
        return 0;
    }
}
int main(void) {
    FAST_IO;
    init();
    int n,m;
    cin >> n >> m;
    int sum,x;
    for(int i=1;i<=n;i++){
        cin >> x;
        sum+=x;
        for(int j=1;j<=x;j++) {
            int s;
            cin >> s;
            mergr(s,i+100);
        }
    }
    if(sum==0){
        cout << n << endl;
        return 0;
    } 
    int ans=0;
    for(int i=1;i<=n;i++){
        if(!mergr(101,100+i)) ans++;
    }
    cout << ans << endl;
    // pause;
    return 0;
}
