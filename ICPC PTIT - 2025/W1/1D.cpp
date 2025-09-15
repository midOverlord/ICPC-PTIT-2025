#include <bits/stdc++.h>

using namespace std;

#define  MAXN  100005

int n, a[MAXN];

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    multiset<int> f;
    for(int i = 1; i <= n; i++) {
        auto it = f.lower_bound(a[i]);
        if(it != f.begin()) f.erase(--it);
        f.insert(a[i]);
    }
    cout << f.size();
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    process();
    return 0;
}