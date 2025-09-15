#include <bits/stdc++.h>

using namespace std;

long long get_sqrt(long long n) {
    long long res = sqrt(n);
    while(res * res > n) res--;
    while((res + 1) * (res + 1) <= n) res++;
    return res;
}

set<long long> num;

void process(void) {
    long long n; cin >> n;
    long long ans = get_sqrt(n);
    for(int b = 3; b <= 59; b++) {
        for(int a = 2; ; a++) {
            long long cur = 1;
            int check = 1;
            for(int i = 1; i <= b; i++) {
                if(cur > n / a) {
                    check = 0;
                    break;
                } else cur *= a;
            }
            if(!check) break;
            long long tmp = get_sqrt(cur);
            if(tmp * tmp != cur) num.insert(cur);
        }
    }
    cout << ans + num.size();
}

signed main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}
