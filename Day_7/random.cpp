#include <bits/stdc++.h>
using namespace std;
using range = std::uniform_int_distribution<long long>::param_type;
int main(void) {
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    mt19937 rand_num(seed);
    uniform_int_distribution<long long> dist(1, 100);
    int t = dist(rand_num);
    cout << t << endl;
    dist.param(range{1LL, 2000000000LL});

    while (t--) {
        cout << dist(rand_num) << endl;
    }

    // system("pause");
    return 0;
}