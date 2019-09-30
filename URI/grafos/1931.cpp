#include <bits/stdc++.h>

using namespace std;
#define MAXN 100009
#define INF 0x3f3f3f3f
#define F first
#define S second
#define mp make_pair
#define rep(i, a, b) for(int i = a; i < (b); i++)
//first par, second impar

typedef pair<int ,int> ii;

int vertices[MAXN], n, m;
vector<ii> adjList[MAXN];
ii dist[MAXN];

int dijkstra(int s, int t) {
	for(int i = 1; i <= n; i++) dist[i] = ii(INF, INF);
	set<pair<ii, int>> pq;
	dist[s] = ii(0, INF);
	pq.insert(mp(dist[s], s));
	while(!pq.empty()) {
		int u = pq.begin()->second;
		pq.erase(pq.begin());
		for(int i=0; i<(int)adjList[u].size(); i++) {
			int v = adjList[u][i].second;
			int w = adjList[u][i].first;
			if (dist[v].S > dist[u].F + w) {
				pq.erase(mp(dist[v], v));
				dist[v].S = dist[u].F + w;
				pq.insert(mp(dist[v], v));
			}
			if (dist[v].F > dist[u].S + w) {
				pq.erase(mp(dist[v], v));
				dist[v].F = dist[u].S + w;
				pq.insert(mp(dist[v], v));
			}
		}
	}
	return dist[t].F == INF ? -1: dist[t].F;
}

int main(){
    cin >> n >> m;
    rep(i, 1, m + 1){
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].push_back(ii(w, v));
        adjList[v].push_back(ii(w, u));
    }
    cout << dijkstra(1, n) << '\n';
    return 0;
}
