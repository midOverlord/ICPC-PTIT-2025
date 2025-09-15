#include <bits/stdc++.h>

using namespace std;

unsigned long long C[65][65];

void process(void) {
    for(int k = 1; k <= 60; k++) {
        C[k][0] = C[k][k] = 1;
        for(int n = 1; n < k; n++) {
            C[k][n] = C[k - 1][n - 1] + C[k - 1][n];
        }
    }
    unsigned long long a, b, k; cin >> a >> b >> k;
    while(a > 0 || b > 0) {
        if(a == 0) {
            cout << 'b';
            b--;
        } else if(b == 0) {
            cout << 'a';
            a--;
        } else {
            unsigned long long cur = C[a + b - 1][a - 1];
            if(k <= cur) {
                cout << 'a';
                a--;
            } else {
                cout << 'b';
                k -= cur;
                b--;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}