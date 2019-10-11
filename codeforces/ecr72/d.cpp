#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5;
#define UNVISITED 0
#define VISITED 1
#define EXPLORED 2
int n, m, k, vis[MAXN], parent[MAXN];
vi adj[MAXN]; 
pii edge[MAXN];
map<pii, int> mp;

void check(int u){
    vis[u] = EXPLORED;
    trav(a, adj[u]){
        if (vis[a] == UNVISITED){
            parent[a] = u;
            check(a);
        }
        else if (vis[a] == EXPLORED){
        //cout << "Back Edge: (" << u+1 << ", " << a+1 << ")\n";
            
          //      cout << "Back Edge: (" << u+1 << ", " << a+1 << ")\n";
                k = 2;
                mp[pii(u,a)] = 2;
                
            
        }
    }
    vis[u] = VISITED;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m;
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        //adj[b].push_back(a);
        edge[i] = pii(a,b);
        mp.insert({pii(a,b), 1});
    }
    iota(parent, parent + n, 0);
    k= 1;
    rep(i, 0, n){
        if(vis[i] == UNVISITED)
            check(i);
    }
    cout << k << '\n';
    rep(i, 0, m){
        cout << mp[edge[i]] << (i == m - 1 ? '\n' : ' '); 
    }
    return 0;
}
