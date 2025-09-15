#include <bits/stdc++.h>

using namespace std;

void process(void) {
    string s; cin >> s;
    int a = s[0] - '0', b = s[1] - '0', c = s[2] - '0';
    cout << (a + b + c) * (100 + 10 + 1);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}