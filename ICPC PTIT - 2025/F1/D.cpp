#include <bits/stdc++.h>

using namespace std;

int n;

string s;

void process(void) {
    cin >> n >> s;
    int i = 0;
    long long ans = 0;
    while(i < n) {
        int cnt = 1;
        while(i + 1 < n && s[i + 1] == s[i]) {
            i++;
            cnt++;
        }
        ans += 1LL * cnt * (cnt - 1) / 2;
        i++;
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}