#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
#define pause system("pause")
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
map<string, int> mp;
int main(void) {
	FAST_IO;
	int n;
	cin >> n;
	for (int i = 0; i < n;  i++) {
		string s;
		cin >> s;
		mp[s]++;
	}

	cout << mp.size() << endl;

	// pause;	
	return 0;
}
