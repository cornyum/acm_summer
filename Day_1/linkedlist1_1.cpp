#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)

struct order{
    int d, o;
    order(const int &d = 0, const int &o = 0) : d(d), o(o) {}
};

struct node {
    order data;
    node *pnext;
    node(const order &d = order(), node * p = nullptr) : data(d), pnext(p) {}
};

void insert()
{
    
}

int main(void)
{

    system("pause");
    return 0;
}