#include <bits/stdc++.h>

using namespace std;

#define  MAXN  102

int n;

long long x[MAXN], y[MAXN];

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i++) {
        long long dist = -1, id = -1;
        for(int j = 1; j <= n; j++) if(i != j) {
            long long sqX = x[i] - x[j], sqY = y[i] - y[j];
            long long cur = 1LL * sqX * sqX + 1LL * sqY * sqY;
            if(dist < cur) {
                dist = cur;
                id = j;
            }
        }
        cout << id << '\n';
    }
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}