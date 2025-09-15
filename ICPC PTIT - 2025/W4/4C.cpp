#include <bits/stdc++.h>

using namespace std;

#define  MAXN  1003

int n, a[MAXN][MAXN];

void process(void) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            char x; cin >> x;
            a[i][j] = (x == '#');
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j + 5 <= n) {
                int cnt = 0;
                for(int k = 0; k < 6; k++) cnt += a[i][j + k];
                if(cnt >= 4) return void(cout << "Yes");
            }
            if(i + 5 <= n) {
                int cnt = 0;
                for(int k = 0; k < 6; k++) cnt += a[i + k][j];
                if(cnt >= 4) return void(cout << "Yes");
            }
            if(i + 5 <= n && j + 5 <= n) {
                int cnt = 0;
                for(int k = 0; k < 6; k++) cnt += a[i + k][j + k];
                if(cnt >= 4) return void(cout << "Yes");
            }
            if(i - 5 >= 1 && j + 5 <= n) {
                int cnt = 0;
                for(int k = 0; k < 6; k++) cnt += a[i - k][j + k];
                if(cnt >= 4) return void(cout << "Yes");
            }
        }
    }
    cout << "No";
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}