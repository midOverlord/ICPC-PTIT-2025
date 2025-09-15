#include <bits/stdc++.h>

using namespace std;

#define  MAXN  200005

int n;

string a[MAXN];

bool cmp(string x, string y) {
    if(x.size() != y.size()) return x.size() > y.size();
    return x + y > y + x;
}

bool ex_cmp(string x, string y) {
    return x + y > y + x;
}

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);
    if(a[1].size() == a[2].size() && a[2].size() == a[3].size()) cout << a[1] << a[2] << a[3];
    else {
        sort(a + 1, a + 4, ex_cmp);
        cout << a[1] << a[2] << a[3];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}