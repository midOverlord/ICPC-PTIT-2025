#include <bits/stdc++.h>

using namespace std;

#define  MAXN  100005

int n, c, a[MAXN];

void process(void) {
    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, r = n, ans = 0;
    while(l <= r) {
        if(a[l] + a[r] <= c) l++;
        r--;
        ans++;
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}