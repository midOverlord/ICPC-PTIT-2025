#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 6;

const int N = 1e6;

int cnt[MAXN];

void preprocess(void) {
    for(int i = 1; i <= N; i++) {
        vector<int> a;
        int x = i;
        while(x) {
            a.push_back(x % 10);
            x /= 10;
        }
        int diff = 0;
        for(int j = 0; j < a.size() / 2; j++) {
            if(a[j] != a[a.size() - j - 1]) diff++;
            if(diff > 1) break;
        }
        cnt[i] = cnt[i - 1] + (diff <= 1);
    }
}

void process(void) {
    int a, b; cin >> a >> b;
    cout << cnt[b] - cnt[a - 1] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    preprocess();
    int T; cin >> T; while(T--) process();
    return 0;
}