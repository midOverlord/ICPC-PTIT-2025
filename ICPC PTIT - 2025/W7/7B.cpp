#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5;

int n, a[MAXN], mark[MAXN];

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) mark[a[i]] = 1;
    int l = *min_element(a + 1, a + n + 1), r = *max_element(a + 1, a + n + 1);
    for(int i = l; i <= r; i++) if(!mark[i]) return void(cout << i);
}

signed main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}
