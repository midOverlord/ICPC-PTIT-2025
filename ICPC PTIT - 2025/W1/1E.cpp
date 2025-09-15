#include <bits/stdc++.h>

using namespace std;

long long f[75];

void process(void) {
    f[1] = 1;
    for(int i = 2; i <= 73; i++) f[i] = f[i - 1] + f[i - 2];
    long long n; cin >> n;
    long long ans = 0;
    for(int i = 73; i >= 1; i--) if(n >= f[i]) {
        n -= f[i];
        ans = f[i];
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    process();
    return 0;
}