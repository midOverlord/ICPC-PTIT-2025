#include <bits/stdc++.h>

using namespace std;

#define  MAXN  1000006

const int N = 1e6;

int cnt[MAXN];

void sieve(void) {
    for(int i = 1; i <= N; i++) cnt[i] = 1;
    for(int i = 2; i <= N; i++) {
        for(int j = i; j <= N; j += i) cnt[j]++;
    }
}

void process(void) {
    sieve();
    long long x; cin >> x;
    long long tmp = sqrt(x);
    while(tmp * tmp < x) tmp++;
    while(tmp * tmp > x) tmp--;
    bool check = 1;
    for(int i = 2; i <= sqrt(tmp); i++) {
        if(tmp % i == 0) check = 0;
    }
    int ans = 0;
    if(check == 1 && tmp * tmp == x) ans = tmp;
    for(int i = 1; i <= N; i++) {
        long long cur = 1;
        bool check = 1;
        for(int j = 1; j <= cnt[i]; j++) {
            if(cur > x / i) check = 0;
            else cur *= i;
        }
        if(check && cur == x) return void(cout << i);
    }
    cout << (ans == 0 ? -1 : ans);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}