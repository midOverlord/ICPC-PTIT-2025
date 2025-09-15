#include <bits/stdc++.h>

using namespace std;

void process(void) {
    int k, s; cin >> k >> s;
    long long ans = 0;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= k; j++) {
            if(s >= i + j && s - i - j <= k) ans++;
        }
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}