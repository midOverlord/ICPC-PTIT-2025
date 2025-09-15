#include <bits/stdc++.h>

using namespace std;

#define  MAXN  102

double dp[MAXN][MAXN][MAXN];

double backtrack(int a, int b, int c, int step) {
    if(a == 100 || b == 100 || c == 100) return step;
    if(dp[a][b][c] != 0) return dp[a][b][c];
    if(a != 0) {
        dp[a][b][c] += backtrack(a + 1, b, c, step + 1) * a / (a + b + c);
    }
    if(b != 0) {
        dp[a][b][c] += backtrack(a, b + 1, c, step + 1) * b / (a + b + c);
    }
    if(c != 0) {
        dp[a][b][c] += backtrack(a, b, c + 1, step + 1) * c / (a + b + c);
    }
    return dp[a][b][c];
}

void process(void) {
    int a, b, c; cin >> a >> b >> c;
    cout << setprecision(6) << fixed << backtrack(a, b, c, 0);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}