#include <bits/stdc++.h>

using namespace std;

#define  MAXN  200005

int n, k, a[MAXN], pref[MAXN];

map<int, vector<int>> cnt;

void process(void) {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pref[i] = (pref[i - 1] + a[i]) % k;
    long long ans = 0;
    cnt[0].push_back(0);
    for(int i = 1; i <= n; i++) {
        int cur = (pref[i] - (i % k) + k) % k;
        ans += (cnt[cur].size() - (upper_bound(cnt[cur].begin(), cnt[cur].end(), i - k) - cnt[cur].begin()));
        cnt[cur].push_back(i);
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}