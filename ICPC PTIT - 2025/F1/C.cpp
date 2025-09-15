#include <bits/stdc++.h>

using namespace std;

#define  MAXN  200005

int n, a[MAXN];

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, greater<int>());
    int cur = 1;
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += 1LL * a[i] * (n - cur);
        cur += 2;
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}