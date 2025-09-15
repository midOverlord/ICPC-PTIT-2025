#include <bits/stdc++.h>

using namespace std;

void process(void) {
    char a, b; cin >> a >> b;
    string as = "", bs = "";
    for(int i = 0; i < (b - '0'); i++) as += a;
    for(int i = 0; i < (a - '0'); i++) bs += b;
    if(as < bs) cout << as;
    else cout << bs;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}