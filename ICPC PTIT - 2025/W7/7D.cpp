#include <bits/stdc++.h>

using namespace std;

#define  MASK(i)  (1LL << (i))
#define  BIT(x, i)  (((x) >> (i)) & 1)

const int MAXN = 21;

int n, dist[MAXN][MAXN];

long long dp[MASK(16) + 5];

void process(void) {
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j <= n - 1; j++) cin >> dist[i][j];
    }
    long long ans = 0;
    for(int mask = 0; mask <= MASK(n) - 1; mask++) {
        for(int i = 0; i < n; i++) if(!BIT(mask, i)) {
            for(int j = i + 1; j < n; j++) if(!BIT(mask, j)) {
                int _mask = mask ^ MASK(i) ^ MASK(j);
                dp[_mask] = max(dp[_mask], dp[mask] + dist[i][j]);
                ans = max(ans, dp[_mask]);
            }
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}
