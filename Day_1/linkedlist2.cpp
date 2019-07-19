#include <bits/stdc++.h>
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
typedef long long ll;
typedef unsigned int UINT;
typedef unsigned long long ull;
using namespace std;
int const maxn = 2e5 + 10;
struct node {
    int data, pre, next;
};
struct order{
    int x, o;
    bool operator<(const order& p) const {
        return x < p.x;
    }
    order(const int &x = 0, const int &w = 0) : x(x),o(w) {}
};
node a[maxn];
set<order> st;
int cnt = 0, head = 0, tail = 1;
void init(){
    a[cnt].pre = -1;
    a[cnt].next = 1;
    cnt = 0;
}

void remove(int p)
{   
    cnt--;
    a[a[p].pre].next = a[p].next;
    a[a[p].next].pre = a[p].pre;
}

int main(void)
{
    FAST_IO;
    int n, k;
    cin >> n >> k;
    init();
    for (int i = 1; i <= n; i++)
    {
        cnt++;
        cin >> a[i].data;
        st.insert(order(a[i].data, i));
        a[i].pre = i - 1;
        a[i].next = i + 1;
        tail = i + 1;
    }
    int f = 1;
    while (cnt > 0)
    {
        int x = 0, t = 0;
        auto mx = st.rbegin();
        t = mx->o;
        st.erase(*mx);
        int temp = t;
        for (int i = 0; i < k; i++)
        {
            if (a[temp].pre == head)
                break;
            temp = a[temp].pre;
            st.erase(order(a[temp].data, temp));
            a[temp].data = f;
            remove(temp);
        }
        temp = t;
        for (int i = 0; i < k; i++)
        {
            if (a[temp].next == tail)
                break;
            temp = a[temp].next;
            st.erase(order(a[temp].data, temp));
            a[temp].data = f;
            remove(temp);
        }
        st.erase(order(a[t].data, t));
        a[t].data = f;
        remove(t);
        if (f == 1) f = 2;
        else f = 1;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i].data;

    cout << endl;
    // system("pause");
    return 0;
}
