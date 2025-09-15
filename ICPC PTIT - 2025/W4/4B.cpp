#include <bits/stdc++.h>

using namespace std;

#define  MAXN  200005

int n, m, a[MAXN], b[MAXN];

void process(void) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        int j = lower_bound(b + 1, b + m + 1, a[i]) - b;
        ans = min(ans, abs(a[i] - b[j]));
        if(j > 1) ans = min(ans, abs(a[i] - b[j - 1]));
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}