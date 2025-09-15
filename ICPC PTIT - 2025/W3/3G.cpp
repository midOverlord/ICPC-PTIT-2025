#include <bits/stdc++.h>

using namespace std;

#define  MAXN  100005

const int INF = 1e9 + 9;

int n, m, a[MAXN];

multiset<int> st[MAXN * 4];

void build(int id, int l, int r) {
    if(l == r) return void(st[id].insert(a[l]));
    int mid = r + l >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    for(int x: st[id * 2]) st[id].insert(x);
    for(int x: st[id * 2 + 1]) st[id].insert(x);
}

void update(int id, int l, int r, int pos, int val) {
    if(l == r) {
        while(id) {
            st[id].erase(st[id].find(a[pos]));
            st[id].insert(val);
            id /= 2;
        }
        return;
    }
    int mid = r + l >> 1;
    if(pos <= mid) update(id * 2, l, mid, pos, val);
    else update(id * 2 + 1, mid + 1, r, pos, val);
}

int get(int id, int l, int r, int u, int v, int val) {
    if(v < l || r < u) return INF;
    if(u <= l && r <= v) {
        auto it = st[id].upper_bound(val);
        if(it == st[id].end()) return INF;
        return *it;
    }
    int mid = r + l >> 1;
    return min(get(id * 2, l, mid, u, v, val), get(id * 2 + 1, mid + 1, r, u, v, val));
}

void process(void) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for(int i = 1; i <= m; i++) {
        int cmd; cin >> cmd;
        if(cmd == 1) {
            int u, val; cin >> u >> val;
            update(1, 1, n, u, val);
            a[u] = val;
        } else {
            int u, v, x; cin >> u >> v >> x;
            int ans = get(1, 1, n, u, v, x);
            cout << (ans == INF ? -1 : ans) << '\n';
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}