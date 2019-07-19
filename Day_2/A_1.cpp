#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
using namespace std;

struct node {
    int data;
    node *l, *r;
    node(const int &data = 0, node *l = nullptr, node *r = nullptr) : data(data), r(r), l(l) {}
};
int const maxn = 1000 + 100;
int pre[maxn], in[maxn], pos[maxn];
int a[maxn], cnt = 0;
int id;

node *crateTree(int prel, int prer, int inl, int inr){
    if (prel > prer || inl > inr)
        return nullptr;
    node *root = new node(pre[prel]);
    int lc_len = pos[root->data] - inl;
    root->l = crateTree(prel + 1, prel + lc_len, inl, pos[root->data] - 1);
    root->r = crateTree(prel + lc_len + 1, prer, pos[root->data] + 1, inr);
}

void destoryTree(node *root){
    if (!root)
        return;
    destoryTree(root->l);
    destoryTree(root->r);
    delete root;
}
void post(node *root)
{
    if (!root)
        return;
    post(root->l);
    post(root->r);
    a[cnt++] = root->data;
}

int main()
{
    int n;
    while (cin >> n){
        memset(a, 0, sizeof(a));   
        cnt = 0;     
        for (int i = 1; i <= n; i++){
            cin >> pre[i];
        }
        for (int i = 1; i <= n; i++){
            cin >> in[i];
            pos[in[i]] = i;
        }
        node *root = crateTree(1, n, 1, n);
        post(root);
        for (int i = 0; i < cnt; i++)
            if (i != 0) cout << " " << a[i];
            else cout << a[i];
        cout << endl;

        destoryTree(root);
    }

    system("pause");
    return 0;
}