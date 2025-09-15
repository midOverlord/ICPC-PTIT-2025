#include <bits/stdc++.h>

using namespace std;

#define  st  first 
#define  nd  second
#define  MAXN  1003

int n, a[MAXN];

unordered_map<long long, vector<pair<int, int>>> cnt;

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) cnt[a[i] + a[j]].push_back({i, j});
    }
    int ans = 0;
    for(int p = 1; p <= n; p++) {
        int check = 0;
        for(int k = 1; k <= n; k++) {
            long long cur = 1LL * 3 * a[p] - a[k];
            if(cnt.count(cur)) {
                for(int i = 0; i < cnt[cur].size(); i++) {
                    if(k != cnt[cur][i].st && k != cnt[cur][i].nd) {
                        check = 1;
                        break;
                    }
                } 
            }
            if(check) {
                ans++;
                break;
            }
        }
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}