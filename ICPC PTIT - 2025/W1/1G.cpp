#include <bits/stdc++.h>

using namespace std;

#define  MAXN  300005

int n, m, a[MAXN];

bool check(int x) {
    int pre = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] + x < pre) return 0;
        if(a[i] <= pre || (a[i] + x >= m && (a[i] + x) % m >= pre)) continue;
        else pre = a[i];
    }
    return 1;
}

void process(void) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int l = -1, r = m + 1;
    while(r - l > 1) {
        int mid = r + l >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    process();
    return 0;
}