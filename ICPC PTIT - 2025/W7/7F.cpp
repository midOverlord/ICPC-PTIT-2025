#include <bits/stdc++.h>

using namespace std;

int n;

string s, t;

void process(void) {
    cin >> n >> s;
    for(char c: s) {
        if(c == 'A') t += "BB";
        else t += c;
    }
    for(int i = 0; i < t.size(); i++) {
        if(i + 1 < t.size() && t[i] == 'B' && t[i + 1] == 'B') {
            cout << 'A';
            i++;
        } else cout << t[i];
    }
}

signed main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}
