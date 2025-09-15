#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 5;

int n, a[MAXN], st[MAXN * 4];

void update(int id, int l, int r, int pos) {
    if(l == r) return void(st[id]++);
    int mid = r + l >> 1;
    if(pos <= mid) update(id * 2, l, mid, pos);
    else update(id * 2 + 1, mid + 1, r, pos);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if(v < u) return 0;
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = r + l >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += get(1, 1, n, ++a[i], n);
        update(1, 1, n, a[i]);
    }
    for(int k = 1; k <= n; k++) {
        cout << ans << '\n';
        ans -= max(0, (a[k] - 1) - 1 + 1);
        ans += max(0, n - (a[k] + 1) + 1);
    }
}

signed main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}
