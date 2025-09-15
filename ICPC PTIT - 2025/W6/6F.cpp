#include <bits/stdc++.h>

using namespace std;

#define  MAXK  1000006

struct edge {
    int u, v, w;
} adj[MAXK];

bool cmp(edge x, edge y) {
    return x.w < y.w;
}

int n, k, root[MAXK], mark[MAXK];

int get_root(int u) {
    return (root[u] == u ? u : root[u] = get_root(root[u]));
}

void process(void) {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) root[i] = i;
    for(int i = 1; i <= k; i++) cin >> adj[i].u >> adj[i].v >> adj[i].w;
    sort(adj + 1, adj + k + 1, cmp);
    for(int i = 1; i <= k; i++) {
        int ru = get_root(adj[i].u), rv = get_root(adj[i].v);
        if(ru != rv) {
            root[rv] = root[ru];
            mark[i] = 1;
        }
    }
    long long ans = 0;
    for(int i = 1; i <= k; i++) {
        if(!mark[i] && adj[i].w >= 0) ans += adj[i].w;
    }
    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}