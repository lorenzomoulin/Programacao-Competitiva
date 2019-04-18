#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ms(a, x) memset(a, x, sizeof a)
#define trav(a, x) for(auto& a : x)
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define UNVISITED -1
#define EXPLORED -2
#define VISITED -3
#define MAXN 10009

int cofre[MAXN], custo = 0, vis[MAXN], parent[MAXN], c;
vector<pii> adj[MAXN];

void dfs(int u){
    vis[u] = VISITED;
    
    for(int j = 0, v; j < sz(adj[u]); ++j){
        v = adj[u][j].first;
        
        if (vis[v] == UNVISITED){
            parent[v] = u;
            dfs(v);
            custo += 2*ceil(cofre[v]*1.0/c)*adj[u][j].second;
            cofre[u] += cofre[v];
            cofre[v] = 0;
        }  
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    int n;
    cin >> n >> c;
    rep(i, 1, n + 1){
        cin >> cofre[i];
    }
    ms(vis, UNVISITED);
    rep(i, 1, n){
        int a, b, peso;
        cin >> a >> b >> peso;
        adj[a].pb(pii(b, peso));
        adj[b].pb(pii(a, peso));
    }
    dfs(1);
    cout << custo << "\n";
    return 0;
}
