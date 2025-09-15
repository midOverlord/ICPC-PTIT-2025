#include <bits/stdc++.h>

using namespace std;

void process(void) {
    long long x, y; cin >> x >> y;
    cout << (abs(x - y) < 2 ? "Bob" : "Alice");
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}