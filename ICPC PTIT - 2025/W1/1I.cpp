#include <bits/stdc++.h>

using namespace std;

#define  st  first 
#define  nd  second 

vector<pair<int, int>> cnt[502];

int a[502];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    for(int x = 1; x <= 500; x++) {
        int N = x;
        for(int i = 2; i <= sqrt(N); i++) {
            if(N % i == 0) {
                int cur = 0;
                while(N % i == 0) {
                    cur++;
                    N /= i;
                }
                cnt[x].push_back({i, cur});
            }
        }
        if(N > 1) cnt[x].push_back({N, 1});
    }
    int n, k;
    while(cin >> n >> k) {
        for(int i = n - k + 1; i <= n; i++) {
            for(int j = 0; j < cnt[i].size(); j++) {
                a[cnt[i][j].st] += cnt[i][j].nd;
            }
        }
        for(int i = 2; i <= k; i++) {
            for(int j = 0; j < cnt[i].size(); j++) {
                a[cnt[i][j].st] -= cnt[i][j].nd;
            }
        }
        long long ans = 1;
        for(int i = 1; i <= n; i++) if(a[i] > 0) ans *= (a[i] + 1);
        cout << ans << '\n';
        for(int i = 1; i <= 500; i++) a[i] = 0;
    }
    return 0;
}