#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int inf = 1e9;
#define MAXN 1009
#define UNVISITED -1
#define EXPLORED -2
#define VISITED -3

int vis[MAXN], parent[MAXN];
vector<int> adjList[MAXN];
vector<pii> be;

void graphCheck(int u) { // DFS for checking graph edge properties
	vis[u] = EXPLORED;
	
	for (int j = 0, v; j < (int)adjList[u].size(); j++) {
		v = adjList[u][j];
		if (vis[v] == UNVISITED) {
			//printf(" Tree Edge (%d, %d)\n", u, v);
			parent[v] = u; // parent of this children is me
			graphCheck(v);
		}
		else if (vis[v] == EXPLORED) {
			//printf(" Back Edge (%d, %d) (Cycle)\n", u, v);
			be.push_back( {u, v});
		}
		//else if (vis[v] == VISITED)
			//printf(" Forward/Cross Edge (%d, %d)\n", u, v);
	}
	vis[u] = VISITED;
}

int main() {
    //cin.sync_with_stdio(0); cin.tie(0);
    //cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adjList[a].push_back(b);
    }
    iota(parent, parent + n, 0);
    memset(vis, -1, sizeof vis);
    //be = {-1, -1};
    rep(i, 0, n){
        if (vis[i]==UNVISITED)
            graphCheck(i);
    }

    if (sz(be) == 0){
        cout << -1 << '\n';
        return 0;
    }
    int res = inf;
    vi ans;
    trav(b, be){
        vi dist(n, inf); dist[b.second] = 0;
        queue<int> q; q.push(b.second);
        vi p(n);
        p[b.second] = b.second;
        while(!q.empty()){
            int u = q.front(); q.pop();
            trav(a, adjList[u]){
                if (dist[a] == inf){
                    dist[a] = dist[u] + 1;
                    p[a] = u;
                    q.push(a);
                }
            }
        }
        if (dist[b.first] < res){
            ans.clear();
            int u = b.first;
            while (u != p[u]){
                ans.push_back(u);
                u = p[u];
            }
            ans.push_back(u);
            res = dist[b.first] + 1;
        }
        
    }
    cout << res << '\n';
    trav(a, ans) cout << a + 1 << '\n';
    return 0;
}
