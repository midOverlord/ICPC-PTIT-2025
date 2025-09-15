#include <bits/stdc++.h>

using namespace std;

void process(void) {
    long long a, b; cin >> a >> b;
    if(a == b) return void(cout << 0 << '\n');
    long long d = abs(a - b);
    long long ans = ceil((sqrt(1.0 + 8.0 * d) - 1) / 2);
    long long cur = ans * (ans + 1) / 2;
    while((cur - d) & 1) {
        ans++;
        cur += ans;
    }
    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    int T; cin >> T; while(T--) process();
    return 0;
}