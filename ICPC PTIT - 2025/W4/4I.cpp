#include <bits/stdc++.h>

using namespace std;

unsigned long long f[20];

void process(void) {
    long long num; cin >> num;
    int s; cin >> s;
    vector<int> a; a.push_back(0);
    long long tmp = num;
    int sum_digit = 0;
    while(tmp) {
        sum_digit += tmp % 10;
        a.push_back(tmp % 10);
        tmp /= 10;
    }
    reverse(a.begin() + 1, a.end());
    int n = a.size() - 1;
    if(sum_digit <= s) return void(cout << 0 << '\n');
    if(a[1] >= s) return void(cout << f[n] - num << '\n');
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        if(cur + a[i] <= s) cur += a[i];
        else {
            for(int j = i; j <= n; j++) a[j] = 0;
            for(int j = i - 1; j >= 1; j--) {
                if(a[j] + 1 < 10 && cur + 1 <= s) {
                    a[j] = a[j] + 1;
                    break;
                } else {
                    cur -= a[j];
                    a[j] = 0;
                }
            }
        }
    }
    unsigned long long ans = 0;
    if(a[1] == 0) ans = 1;
    for(int i = 1; i <= n; i++) ans = ans * 10 + a[i];
    cout << ans - num << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    f[0] = 1;
    for(int i = 1; i <= 19; i++) f[i] = 10 * f[i - 1];
    int T; cin >> T; while(T--) process();
    return 0;
}