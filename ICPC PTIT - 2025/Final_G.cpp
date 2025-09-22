#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;

int n, k, fact[MAXN], ifact[MAXN];

long long POW(long long a, long long b) {
    long long ans = 1;
    while (b > 0){
        if (b % 2) ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}

string a[MAXN], str;
unordered_map<string, int> id;

int A(int n, int k){
    if (k > n) return 0;
    return (1LL * fact[n] % MOD) * ifact[n - k] % MOD;
}

int ans = 0, st[MAXN * 4];
vector<int> v;

void update(int id, int l, int r, int pos) {
    if(l == r) return void(st[id]++);
    int mid = r + l >> 1;
    if(pos <= mid) update(id * 2, l, mid, pos);
    else update(id * 2 + 1, mid + 1, r, pos);
    st[id] = st[id * 2] + st[id * 2 + 1];
}

int get(int id, int l, int r, int u, int v) {
    if(v < u || v < l || r < u) return 0;
    if(u <= l && r <= v) return st[id];
    int mid = r + l >> 1;
    return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
}

void process(void) {
    cin >> n >> k;
    fact[0] = 1;
    fact[0] = ifact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = 1LL * fact[i - 1] * i % MOD;
    ifact[n] = POW(fact[n], MOD - 2);
    for (int i = n - 1; i >= 1; i--) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) id[a[i]] = i;
    cin >> str;
    string cur = "";
    for(int i = 0; i < str.size(); i++) {
        cur += str[i];
        if(id.count(cur)) {
            v.push_back(id[cur]);
            cur = "";
        }
    }
    int ans = 1;
    for(int i = 0; i < v.size(); i++) { 
        k--;
        ans = (ans + 1LL * max(0, v[i] - 1 - get(1, 1, n, 1, v[i] - 1)) * A(n - (i + 1), k)) % MOD;
        update(1, 1, n, v[i]);
    }
    cout << ans;
}

signed main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}
