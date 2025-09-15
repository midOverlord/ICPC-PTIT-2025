#include <bits/stdc++.h>

using namespace std;

#define  MAXV  12

const int MOD = 1e9 + 7;

int n, m, dp[MAXV][MAXV][MAXV], pre[MAXV][MAXV][MAXV];

void process(void) {
    cin >> n >> m;
    dp[m + 1][m + 1][m + 1] = 1;
    for(int o = 1; o <= n; o++) {
        memset(pre, 0, sizeof pre);
        swap(dp, pre);
        for(int i = 1; i <= m + 1; i++) {
            for(int j = 1; j <= m + 1; j++) {
                for(int k = 1; k <= m + 1; k++) {
                    int val = pre[i][j][k];
                    for(int x = 1; x <= m; x++) {
                        if(x <= i) (dp[x][j][k] += val) %= MOD;
                        else if(x <= j) (dp[i][x][k] += val) %= MOD;
                        else if(x <= k) (dp[i][j][x] += val) %= MOD;
                    }
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        for(int j = i + 1; j <= m; j++) {
            for(int k = j + 1; k <= m; k++) (ans += dp[i][j][k]) %= MOD;
        }
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}