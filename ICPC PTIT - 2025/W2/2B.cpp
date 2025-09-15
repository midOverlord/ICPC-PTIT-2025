#include <bits/stdc++.h>

using namespace std;

#define  MAXN  200005

int n, a[MAXN];

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = n; i >= 1; i -= 2) cout << a[i] << ' ';
    for(int i = 1 + (n & 1); i <= n; i += 2) cout << a[i] << ' ';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}