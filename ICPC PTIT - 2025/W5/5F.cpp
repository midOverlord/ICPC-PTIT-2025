#include <bits/stdc++.h>

using namespace std;

#define  MAXN  1003

int n, k, f[MAXN], b[MAXN], c[MAXN], dp[MAXN * 15];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    f[start] = 0;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int v = 1; v <= u; v++) {
            if(u + u / v > 1000) continue;
            if(f[u + u / v] == -1) {
                f[u + u / v] = f[u] + 1;
                q.push(u + u / v);
            }
        }
    }
}

void process(void) {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> b[i];
    for(int i = 1; i <= n; i++) cin >> c[i];
    if(k >= 12 * n) return void(cout << accumulate(c + 1, c + n + 1, 0) << '\n');
    k = min(n * 12, k);
    memset(dp, 0, sizeof dp);
    for(int i = 1; i <= n; i++) {
        for(int j = k; j >= f[b[i]]; j--) {
            dp[j] = max(dp[j], dp[j - f[b[i]]] + c[i]);
        }
    }
    cout << dp[k] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(f, -1, sizeof f);
    bfs(1);
    int T; cin >> T; while(T--) process();
    return 0;
}