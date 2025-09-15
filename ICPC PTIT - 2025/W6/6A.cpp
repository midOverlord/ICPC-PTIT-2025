#include <bits/stdc++.h>

using namespace std;

string s;

int cnt[3];

void process(void) {
    cin >> s;
    int ans = 0;
    for(char c: s) {
        cnt[c - 'A']++;
        if(cnt[0] && cnt[1] && cnt[2]) {
            cnt[0]--; cnt[1]--; cnt[2]--;
        }
        ans = max({ans, cnt[0], cnt[1], cnt[2]});
    }
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}