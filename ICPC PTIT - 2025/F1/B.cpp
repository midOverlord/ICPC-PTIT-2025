#include <bits/stdc++.h>

using namespace std;

#define  MAXN  100005

int n, m, a[MAXN], mark[MAXN];

const int N = 1e5;

int prime[MAXN];

vector<int> p;

void sieve(void) {
    for(int i = 2; i <= N; i++) prime[i] = 1;
    for(int i = 2; i <= sqrt(N); i++) if(prime[i]) {
        for(int j = i * i; j <= N; j += i) {
            prime[j] = 0;
        }
    }
    for(int i = 1; i <= N; i++) if(prime[i]) p.push_back(i);
}

set<int> ans;

vector<int> pmark;

void process(void) {
    sieve();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int x = 2; x <= sqrt(a[i]); x++) {
            if(a[i] % x == 0) {
                if(mark[x] == 0) {
                    pmark.push_back(x);
                    mark[x] = 1;
                }
                while(a[i] % x == 0) a[i] /= x;
            }
        }
        if(a[i] != 1) {
            if(mark[a[i]] == 0) {
                pmark.push_back(a[i]);
                mark[a[i]] = 1;
            }
        }
    }
    for(int i = 0; i < p.size(); i++) if(p[i] <= m && !mark[p[i]]) {
        for(int j = p[i]; j <= m; j += p[i]) {
            ans.insert(j);
        }
    }
    vector<int> pans;
    for(int x: ans) {
        int check = 1;
        for(int i: pmark) if(x % i == 0) check = 0;
        if(check) pans.push_back(x);
    }
    cout << pans.size() + 1 << '\n';
    cout << 1 << ' ';
    for(int x: pans) cout << x << ' ';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}