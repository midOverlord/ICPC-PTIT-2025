#include <bits/stdc++.h>

using namespace std;

#define  MAXN  1003

int n, m, r, c, a[MAXN][MAXN], pref[MAXN][MAXN];

int calc(int r1, int c1, int r2, int c2) {
    return pref[r2][c2] - pref[r2][c1 - 1] - pref[r1 - 1][c2] + pref[r1 - 1][c1 - 1];
}

bool check(int x) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + (a[i][j] <= x);
        }
    }
    for(int i = 1; i + r - 1 <= n; i++) {
        for(int j = 1; j + c - 1 <= m; j++) {
            if(calc(i, j, i + r - 1, j + c - 1) >= r * c / 2 + 1) return true;
        }
    }
    return false;
}

void process(void) {
    cin >> n >> m >> r >> c;
    int l = INT_MAX, r = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            l = min(l, a[i][j]);
            r = max(r, a[i][j]);
        }
    }
    l--; r++;
    while(r - l > 1) {
        int mid = r + l >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}