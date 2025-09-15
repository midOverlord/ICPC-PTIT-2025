#include <bits/stdc++.h>

using namespace std;

#define  MAXN  100005

int n, x[MAXN], y[MAXN];

multiset<int> sum, dif;

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        sum.insert(x[i] + y[i]);
        dif.insert(x[i] - y[i]);
    }
    int ans = INT_MAX;
    for(int i = 1; i <= n; i++) {
        sum.erase(sum.find(x[i] + y[i]));
        dif.erase(dif.find(x[i] - y[i]));
        int cur = max(*prev(sum.end()) - *sum.begin(), *prev(dif.end()) - *dif.begin());
        ans = min(ans, cur);
        sum.insert(x[i] + y[i]);
        dif.insert(x[i] - y[i]);
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}