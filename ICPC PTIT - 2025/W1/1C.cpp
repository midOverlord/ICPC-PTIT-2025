#include <bits/stdc++.h>

using namespace std;

void process(void) {
    string s; cin >> s;
    int l = -1, r = -1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'A' && l == -1) l = i;
        else if(s[i] == 'Z') r = i;
    }
    cout << (l > -1 && r > -1 ? r - l + 1 : 0);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    process();
    return 0;
}