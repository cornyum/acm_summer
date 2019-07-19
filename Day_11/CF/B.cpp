#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
set<string> st;
int m, s, p;
int a[15];

int main(void){
	FAST_IO;
	string a,b,c;
    cin >> a >> b >>c;
    if(a==b && b==c) {
    	cout << 0 << endl;
    	return 0;
	}
    if(a[1]==b[1] && b[1]==c[1]){
    	int x;
    	x=max(max(a[0],b[0]),c[0]);
    	int y;
    	y=min(min(a[0],b[0]),c[0]);
    	if(x-y==2) {
    		if(a[0]==x-1 || b[0]==x-1 || c[0]==x-1){
    			cout << 0 << endl;
    			return 0;
			}
		}
	}
	if(a==b || b==c || a==c){
		cout << 1 << endl;
    	return 0;
	} 
	if(a[1]==b[1] && (abs(a[0]-b[0])==1 || abs(a[0]-b[0])==2)){
		cout << 1 << endl;
    	return 0; 
    } 
	if(a[1]==c[1] && (abs(a[0]-c[0])==1 || abs(a[0]-c[0])==2)){
		cout << 1 << endl;
    	return 0; 
    } 
    if(c[1]==b[1] && (abs(c[0]-b[0])==1 || abs(c[0]-b[0])==2)){
		cout << 1 << endl;
    	return 0; 
    } 
    cout << 2 << endl;
	return 0;
} 