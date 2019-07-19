#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 1000 + 10;
struct node {
    int data, r, l;
    node(const int &data = 0, const int &r = -1, const int &l = -1) : 
        data(data), l(l), r(r){}
}tree[maxn * 2];

int pre[maxn], in[maxn], pos[maxn];
int a[maxn], cnt = 0;
int id;

int bulid(int prel, int prer, int inl, int inr){
    if (prel > prer || inl > inr) 
        return -1;
    ++id;
    int now = id;
    int root = pre[prel];
    int lc_len = pos[root] - inl;
    tree[now].data = root;
    tree[now].l = bulid(prel + 1, prel + lc_len, inl, pos[root] - 1);
    tree[now].r = bulid(prel + lc_len + 1, prer, pos[root] + 1, inr);
    return now;
}

void post(int x)
{
    if (x == -1)
        return;
    post(tree[x].l);
    post(tree[x].r);
    a[cnt++] = tree[x].data;
}

int main(void)
{
    int n;
    while (cin >> n)
    {
        memset(tree, -1, sizeof(tree));
        memset(a, 0, sizeof(a));
        cnt = 0;
        id = 0;
        for (int i = 1; i <= n; ++i){
            cin >> pre[i];
        }
        for (int i = 1; i <= n; ++i){
            cin >> in[i];
            pos[in[i]] = i;
        }
        int root = bulid(1, n, 1, n);
        post(root);
        // cout << cnt << endl;
        // cout << root << endl;
        for (int i = 0; i < cnt; i++)
            if (i != 0) cout << " " << a[i];
            else cout << a[i];
        cout << endl;
    }

    system("pause");
    return 0;
}