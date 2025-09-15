#include <bits/stdc++.h>

using namespace std;

#define  MAXN  302

int n, x[MAXN], y[MAXN];

pair<float, float> calc(int x1, int y1, int x2, int y2) {
    float a = 1.0 * (y1 - y2) / (x1 - x2);
    float b = y1 - a * x1;
    return {a, b};
}

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1;  j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                float tmp = 0.5 * abs(x[i] * (y[j] - y[k]) + x[j] * (y[k] - y[i]) + x[k] * (y[i] - y[j]));
                cnt += (tmp > 0);
            }
        }
    }
    cout << cnt;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    process();
    return 0;
}