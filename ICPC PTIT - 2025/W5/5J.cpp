#include <bits/stdc++.h>

using namespace std;

#define  LI  pair<long long, int>
#define  st  first
#define  nd  second
#define  MAXN  100005

int n, m, X, Y;

struct edge {
    int K, T, V;
};

vector<edge> adj[MAXN];

long long dist[MAXN];

void process(void) {
    cin >> n >> m >> X >> Y;
    for(int i = 1; i <= m; i++) {
        int u, v, t, k; cin >> u >> v >> t >> k;
        adj[u].push_back({k, t, v});
        adj[v].push_back({k, t, u});
    }
    memset(dist, 63, sizeof dist);
    dist[X] = 0;
    priority_queue<LI, vector<LI>, greater<LI>> pq;
    pq.push({0, X});
    while(pq.size()) {
        int cur_time = pq.top().st, u = pq.top().nd;
        pq.pop();
        if(cur_time > dist[u]) continue;
        for(auto e: adj[u]) {
            long long tmp = (dist[u] + e.K - 1) / e.K;
            if(tmp * e.K + e.T < dist[e.V]) {
                dist[e.V] = tmp * e.K + e.T;
                pq.push({dist[e.V], e.V});
            }
        }
    }
    cout << (dist[Y] == dist[0] ? -1 : dist[Y]);
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}