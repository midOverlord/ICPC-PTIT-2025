#include <bits/stdc++.h>

using namespace std;

map<long long, long long> cnt;

void process(void) {
    long long n, p; cin >> n >> p;
    for(int i = 2; i <= sqrt(p); i++) {
        if(p % i == 0) {
            while(p % i == 0) {
                cnt[i]++;
                p /= i;
            }
        }
    }
    if(p > 1) cnt[p]++;
    long long ans = 1;
    for(auto k: cnt) {
        while(k.second >= n) ans *= k.first, k.second -= n;
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}