#include <bits/stdc++.h>

using namespace std;

void process(void) {
    long long f[90];
    int n; cin >> n;
    f[0] = 2; f[1] = 1;
    for(int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    cout << f[n];
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}