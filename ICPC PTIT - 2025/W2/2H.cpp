#include <bits/stdc++.h>

using namespace std;

#define  MAXN  200005

int n, m, d[MAXN];

vector<int> adj[MAXN];

int Count(int node) {
    queue<int> q;
    q.push(node);
    d[node] = 1;
    int cnt = 1;
    while(q.size()) {
        int u = q.front(); q.pop();
        for(int v: adj[u]) if(!d[v]) {
            d[v] = 1;
            q.push(v);
            cnt++;
        }
    }
    return cnt;
}

void process(void) {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) if(!d[i]) ans = max(ans, Count(i));
    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}