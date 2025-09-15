#include <bits/stdc++.h>

using namespace std;

#define  MAXN  102

int n, dp[MAXN][MAXN * MAXN + 5];

struct bottle {
    int x, y;
} a[MAXN];

void process(void) {
    cin >> n;
    int total = 0, MAXV = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].x;
        total += a[i].x;
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[i].y;
        MAXV += a[i].y;
    }
    memset(dp, -30, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j >= 1; j--) {
            for(int k = a[i].y; k <= MAXV; k++) {
                dp[j][k] = max(dp[j][k], dp[j - 1][k - a[i].y] + a[i].x);
            }
        } 
    }
    int K = INT_MAX, T = total;
    for(int i = 1; i <= n; i++) {
        for(int j = total; j <= MAXV; j++) if(dp[i][j] > 0) {
            if(K > i || K == i && T > total - dp[i][j]) {
                K = i;
                T = total - dp[i][j];
            }
        }
    }
    cout << K << ' ' << T;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    process();
    return 0;
}