#include <bits/stdc++.h>

using namespace std;

#define  MAXN  100005

const int base = 31;
const long long MOD = 1000000003;

long long POW[MAXN], h[3][MAXN];

string a[3];

int len[3], in[3][3], cnt[3][3];

long long get_hash(int k, int l, int r) {
    return (h[k][r] - h[k][l - 1] * POW[r - l + 1] + MOD * MOD) % MOD;
}

void process(void) {
    cin >> a[0] >> a[1] >> a[2];
    for(int i = 0; i < 3; i++) {
        len[i] = a[i].length();
        a[i] = ' ' + a[i];
    }
    POW[0] = 1;
    for(int i = 1; i <= 100000; i++) {
        POW[i] = (POW[i - 1] * base) % MOD;
    }
    for(int k = 0; k < 3; k++) {
        for(int i = 1; i <= len[k]; i++) {
            h[k][i] = (h[k][i - 1] * base + a[k][i] - 'a' + 1) % MOD;
        }
    }

    int ans = len[0] + len[1] + len[2];

    for(int i = 1; i <= len[0]; i++) {
        if(len[0] - i + 1 >= len[1]) {
            long long cur = get_hash(0, i, i + len[1] - 1);
            if(cur == get_hash(1, 1, len[1])) in[0][1] = 1;
        }
        if(len[0] - i + 1 >= len[2]) {
            long long cur = get_hash(0, i, i + len[2] - 1);
            if(cur == get_hash(2, 1, len[2])) in[0][2] = 1;
        }
    }
    for(int i = 1; i <= len[1]; i++) {
        if(len[1] - i + 1 >= len[0]) {
            long long cur = get_hash(1, i, i + len[0] - 1);
            if(cur == get_hash(0, 1, len[0])) in[1][0] = 1;
        }
        if(len[1] - i + 1 >= len[2]) {
            long long cur = get_hash(1, i, i + len[2] - 1);
            if(cur == get_hash(2, 1, len[2])) in[1][2] = 1;
        }
    }
    for(int i = 1; i <= len[2]; i++) {
        if(len[2] - i + 1 >= len[0]) {
            long long cur = get_hash(2, i, i + len[0] - 1);
            if(cur == get_hash(0, 1, len[0])) in[2][0] = 1;
        }
        if(len[2] - i + 1 >= len[1]) {
            long long cur = get_hash(2, i, i + len[1] - 1);
            if(cur == get_hash(1, 1, len[1])) in[2][1] = 1;
        }
    }

    for(int i = 1; i <= len[0]; i++) {
        long long cur = get_hash(0, i, len[0]);
        int l = 1, r = 1 + (len[0] - i + 1) - 1;
        if(r <= len[1] && cur == get_hash(1, l, r)) cnt[0][1] = max(cnt[0][1], r - l + 1);
        if(r <= len[2] && cur == get_hash(2, l, r)) cnt[0][2] = max(cnt[0][2], r - l + 1);
    }
    for(int i = 1; i <= len[1]; i++) {
        long long cur = get_hash(1, i, len[1]);
        int l = 1, r = 1 + (len[1] - i + 1) - 1;
        if(r <= len[0] && cur == get_hash(0, l, r)) cnt[1][0] = max(cnt[1][0], r - l + 1);
        if(r <= len[2] && cur == get_hash(2, l, r)) cnt[1][2] = max(cnt[1][2], r - l + 1);
    }
    for(int i = 1; i <= len[2]; i++) {
        long long cur = get_hash(2, i, len[2]);
        int l = 1, r = 1 + (len[2] - i + 1) - 1;
        if(r <= len[0] && cur == get_hash(0, l, r)) cnt[2][0] = max(cnt[2][0], r - l + 1);
        if(r <= len[1] && cur == get_hash(1, l, r)) cnt[2][1] = max(cnt[2][1], r - l + 1);
    }

    if(in[0][1] && in[0][2]) {
        ans = min(ans, len[0]);
    } else if(in[0][1]) {
        ans = min(ans, len[0] + len[2] - max(cnt[2][0], cnt[0][2]));
    } else if(in[0][2]) {
        ans = min(ans, len[0] + len[1] - max(cnt[0][1], cnt[1][0]));
    } else {
        ans = min(ans, len[0] + len[1] + len[2] - cnt[0][1] - cnt[1][2]);
        ans = min(ans, len[0] + len[2] + len[1] - cnt[0][2] - cnt[2][1]);
    }

    if(in[1][0] && in[1][2]) {
        ans = min(ans, len[1]);
    } else if(in[1][0]) {
        ans = min(ans, len[1] + len[2] - max(cnt[1][2], cnt[2][1]));
    } else if(in[1][2]) {
        ans = min(ans, len[1] + len[0] - max(cnt[1][0], cnt[0][1]));
    } else {
        ans = min(ans, len[1] + len[0] + len[2] - cnt[1][0] - cnt[0][2]);
        ans = min(ans, len[1] + len[2] + len[0] - cnt[1][2] - cnt[2][0]);
    }

    if(in[2][0] && in[2][1]) {
        ans = min(ans, len[2]);
    } else if(in[2][0]) {
        ans = min(ans, len[2] + len[1] - max(cnt[2][1], cnt[1][2]));
    } else if(in[2][1]) {
        ans = min(ans, len[2] + len[0] - max(cnt[2][0], cnt[0][2]));
    } else {
        ans = min(ans, len[2] + len[0] + len[1] - cnt[2][0] - cnt[0][1]);
        ans = min(ans, len[2] + len[1] + len[0] - cnt[2][1] - cnt[1][0]);
    }

    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}