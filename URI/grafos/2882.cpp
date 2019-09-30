#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pii> adjU[MAXN];
int pairU[MAXN], pairV[MAXN], dist[MAXN];
int m, n, arestas;

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= m; u++) {
        if (pairU[u] == 0) {
            dist[u] = 0; q.push(u);
        }
        else dist[u] = INF;
    }
    dist[0] = INF;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] >= dist[0]) continue;
        for (int i = 0; i < (int)adjU[u].size(); i++) {
            int v = adjU[u][i].first;
            int w = adjU[u][i].second;
            if (dist[pairV[v]] == INF) {
                dist[pairV[v]] = dist[u] + w;
                q.push(pairV[v]);
            }
        }
    }
    return (dist[0] != INF);
}
bool dfs(int u) {
    if (u == 0) return true;
    for (int i = 0; i < (int)adjU[u].size(); i++) {
        int v = adjU[u][i].first;
        int w = adjU[u][i].second;
        if (dist[pairV[v]] == dist[u]+w) {
            if (dfs(pairV[v])) {
                pairV[v] = u; pairU[u] = v;
                return true;
            }
        }
    }
    dist[u] = INF;
    return false;
}
int hopcroftKarp() {
    memset(&pairU, 0, sizeof pairU);
    memset(&pairV, 0, sizeof pairV);
    int result = 0;
    while (bfs()) {
        for (int u=1; u<=m; u++) {
            if (pairU[u]==0 && dfs(u))
                result++;
        }
    }
    return result;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    cin >> n >> m >> arestas;
    
    
    return 0;
}
