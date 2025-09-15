#include <bits/stdc++.h>

using namespace std;

#define  MAXN  102

int n, a[MAXN];

struct edge {
    int x, y, z;
};

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int cnt = 0;
    vector<edge> v;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            for(int k = j + 1; k <= n; k++) {
                if(a[i] != a[j] && a[j] != a[k] && a[i] != a[k]) {
                    if(a[i] + a[j] > a[k] && a[j] + a[k] > a[i] && a[k] + a[j] > a[i]) {
                        int check = 1;
                        for(auto p: v) {
                            if(p.x == a[i] && p.y == a[j] && p.z == a[k]) check = 0;
                        }
                        cnt += check;
                    }
                }
            }
        }
    }
    cout << cnt;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}