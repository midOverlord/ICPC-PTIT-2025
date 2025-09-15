#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, a[MAXN], b[MAXN];

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    if(a[1] != b[1] || a[n] != b[n]) return void(cout << "No");
    vector<int> dA, dB;
    for(int i = 1; i < n; i++) dA.push_back(a[i + 1] - a[i]);
    for(int i = 1; i < n; i++) dB.push_back(b[i + 1] - b[i]);
    sort(dA.begin(), dA.end());
    sort(dB.begin(), dB.end());
    for(int i = 0; i < n - 1; i++) if(dA[i] != dB[i]) return void(cout << "No");
    cout << "Yes";
}   

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}
