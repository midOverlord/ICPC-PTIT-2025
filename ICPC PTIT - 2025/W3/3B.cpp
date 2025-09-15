#include <bits/stdc++.h>

using namespace std;

#define  MAXN  100005

int n, a[MAXN], pref[MAXN];

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] ^ a[i];
    a[n + 1] = INT_MAX;
    int ans = n - 1;
    if(n == 2) return void(cout << -1);
    for(int mid = 1; mid <= n; mid++) {
        for(int l = 1; l <= mid; l++) {
            for(int r = mid + 1; r <= n; r++) {
                if((pref[mid] ^ pref[l - 1]) > (pref[r] ^ pref[mid])) {
                    ans = min(ans, r - l + 1 - 2);
                    if(ans == 1) return void(cout << ans);
                }
            }
        }
    }
    cout << (ans == n - 1 ? -1 : ans);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}