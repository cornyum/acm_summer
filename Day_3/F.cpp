// #include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define FAST_IO std::ios::sync_with_stdio(false),std::cout.tie(0),std::cin.tie(0)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;
int const maxn = 210 * (210 - 1) / 2;
int n, m;
int father[maxn];
int cnt = 0;
struct node{
    int x, y;
    double w;
    bool operator<(const node & p) const {
        return w < p.w;
    }
    node(const int &u = 0, const int &v = 0) : 
        x(u), y(v) { }
};
struct point {
    double x, y;
    point(const double &u = 0, const double &v = 0) : 
        x(u), y(v) { }
}p[maxn];
node e[maxn];
void init(){
    for (int i = 1; i <= n; i++){
        father[i] = i;
    }
}

int find(int x){
    return x == father[x] ? x : father[x] = find(father[x]);
}

double Kruskal(){
    sort(e, e + cnt);
    for (int i = 0; i < cnt; i++){
        int x = e[i].x;
        int y = e[i].y;
        int a = find(x),b = find(y);
        if (a != b) {
            
            father[b] = a;
            if (find(2) == find(1)){
                return e[i].w;
            }
        }
    }
}

int main(void){
    FAST_IO;
    int nn = 0;
    while (cin >> n && n != 0) {
        // if (nn != 0) cout << endl;
        for (int i = 1; i <= n; i++){
            cin >> p[i].x >> p[i].y;
        }
        // int m = n * (n - 1) / 2;
        cnt = 0;
        for (int i = 1; i <= n ; i++) {
            for (int j = i + 1; j <= n; j++){
                double dis = sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y));
                e[cnt].x = i;
                e[cnt].y = j;
                e[cnt].w = dis;
                cnt++;
            }
        }
        init();
        cout << "Scenario #" << ++nn <<endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << Kruskal() << endl << endl;
    }

    // system("pause");
    return 0;
}

/*
2
0 0
3 4
3
17 4
19 4
18 5
0
 */