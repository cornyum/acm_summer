#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
int const maxn = 100000 + 10;
struct Node {
    ll data;
    int pre, next;
    Node(const ll &data = 0, const int &pre = 0, const int &next = 0) : 
        data(data), pre(pre), next(next) {}
}node[maxn];
int vis[maxn];
struct pnode {
    ll value;
    int pos;
    bool operator<(const pnode & x) const {
        return value > x.value;
    }
    pnode(const ll &v = 0, const int &pos = 0) : value(v), pos(pos) {}
};
priority_queue<pnode> pq;
ll a[maxn];
int cnt;
void remove(int p)
{
    --cnt;
    node[node[p].pre].next = node[p].next;
    node[node[p].next].pre = node[p].pre;
}

void insert(int val)
{
    node[++cnt] = Node(val, cnt - 1, 0);
    node[cnt - 1].next = cnt;
}

void clear(void)
{
    memset(node, 0, sizeof(node));
}

int main(void){
    FAST_IO;
    // clear();
    int n, k;
    cin >> n >> k;
    for (int i  = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i + 1] - a[i];
        pq.push(pnode(a[i], i));
        insert(a[i]);
    }
    node[0].data = node[++cnt].data = 0x3f3f3f3f;
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        pnode tp = pq.top();
        if (pq.size() != 0)
            pq.pop();
        while (vis[tp.pos] && pq.size() != 0){
            tp = pq.top();
            pq.pop();
        }
        ans += node[tp.pos].data;
        // cout << "ans = " << ans << endl;
        int pre = node[tp.pos].pre, next = node[tp.pos].next;
        node[tp.pos].data = node[pre].data + node[next].data - node[tp.pos].data;
        tp.value = node[tp.pos].data;
        remove(pre);
        remove(next);
        pq.push(tp);
        vis[pre] = 1;
        vis[next] = 1;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}