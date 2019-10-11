#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 255
#define INF 0x3f3f3f3f
vector<pii> adj[MAXN];
int n,m,c,k, dist[MAXN];

int dijkstra(int s, int t){
    rep(i, 0, n)    dist[i] = INF;
    dist[s] = 0;
    set<pii> nodes;
    nodes.insert(pii(0,s));
    while(!nodes.empty()){
        int u = nodes.begin()->second;
        nodes.erase(nodes.begin());
        trav(a, adj[u]){
            int v = a.second;
            int w = a.first;
            if (dist[v] > dist[u] + w){
                if (dist[v] > INF)
                    nodes.erase(pii(dist[v], v));
                dist[v] = dist[u] + w;
                nodes.insert(pii(dist[v], v));
            }
        }
    }
    return dist[t];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    while (true){
        cin >> n >> m >> c >> k;
        if (n + m+c+k==0)
            break;
        rep(i,0, MAXN)
            adj[i].clear();
        rep(i, 0, m){
            int u,v,w;
            cin >> u >> v >> w;
            if (max(u,v)<c && abs(u-v)>1){
                adj[u].push_back(pii(INF,v));
                adj[v].push_back(pii(INF,u));
            }
            else{
                adj[u].push_back(pii(w,v));
                adj[v].push_back(pii(w,u));
            }
        }
        cout << dijkstra(k, c-1) << '\n';
    }
    return 0;
}
