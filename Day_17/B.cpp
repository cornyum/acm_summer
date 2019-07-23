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

int main(void) {
    FAST_IO;
    string s;
    int n;
    cin>>n>>s;
    int sum1=0,sum2=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='0'){
            sum1++;
        }
        else{
            sum2++;
        }
    }
    if (sum1 != sum2){
        cout<<1<<endl;
        cout<<s<<endl;
    }else {
        cout<<2<<endl;
        cout<<s[0]<<" ";
        for(int i=1;i<s.length();i++){
            cout<<s[i];
        }
        cout <<endl;
    }
    // pause;
    return 0;
}
