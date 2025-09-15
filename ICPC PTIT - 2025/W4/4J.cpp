#include <bits/stdc++.h>

using namespace std;

#define  st  first 
#define  nd  second
#define  MAXN  1003

int n, m, a[MAXN][MAXN], visited[MAXN][MAXN];

int dirX[] = {0, 0, 1, -1};
int dirY[] = {-1, 1, 0, 0};

bool valid(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y];
}

long long bfs(int X, int Y) {
    queue<pair<int, int>> q;
    q.push({X, Y});
    visited[X][Y] = 1;
    long long res = 6 * a[X][Y] - 2 * (a[X][Y] - 1);
    while(q.size()) {
        int u = q.front().st, v = q.front().nd;
        q.pop();
        for(int i = 0; i < 4; i++) {
            int x = u + dirX[i], y = v + dirY[i];
            if(valid(x, y)) {
                if(!visited[x][y]) {
                    res += 6 * a[x][y] - 2 * (a[x][y] - 1);
                    visited[x][y] = 1;
                    q.push({x, y});
                }
                res -= min(a[x][y], a[u][v]);
            }
        }
    }
    return res;
}

void process(void) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    }
    memset(visited, 0, sizeof visited);
    long long ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) if(!visited[i][j] && a[i][j]) {
            ans += bfs(i, j);
        }
    }
    cout << ans << '\n';
}   

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) process();
    return 0;
}