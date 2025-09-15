#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1e5;

void process(void) {
    int a; cin >> a;
    for(int i = 1; i <= MAXV; i++) {
        if(1LL * i * i >= 2LL * a * a || i == a) continue;
        int j = sqrt(2LL * a * a - 1LL * i * i);
        if(j <= MAXV && 1LL * i * i + 1LL * j * j == 2LL * a * a) return void(cout << "YES");
    }
    cout << "NO";
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}