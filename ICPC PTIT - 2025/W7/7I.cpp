#include <bits/stdc++.h>

using namespace std;

void process(void) {
    long long a[3][2];
    for(int i = 0; i < 3; i++) cin >> a[i][0] >> a[i][1];
    long long edge[3];
    for(int i = 0; i < 3; i++) {
        long long X = a[i][0] - a[(i + 1) % 3][0];
        long long Y = a[i][1] - a[(i + 1) % 3][1];
        edge[i] = X * X + Y * Y;
    }
    long long sum = accumulate(edge, edge + 3, 0LL);
    for(int i = 0; i < 3; i++) {
        if(edge[i] * 2 == sum) return void(cout << "Yes");
    }
    cout << "No";
}

signed main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}
