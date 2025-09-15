#include <bits/stdc++.h>

using namespace std;

void process(void) {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    int sum_side = accumulate(a.begin(), a.end(), 0);
    int max_side = *max_element(a.begin(), a.end());
    cout << (max_side * 2 < sum_side ? "Yes" : "No");
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}