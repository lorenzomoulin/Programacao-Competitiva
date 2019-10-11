#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9;
const int MAXN = 1e3+9;

int n, m, s, t, p[MAXN];
vi adj[MAXN];

int mat[MAXN][MAXN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m >> s >> t;
    s-- ,t--;
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    
    vi dists(n, INF); dists[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        trav(v, adj[u]){
            if (dists[v] == INF){
                dists[v] = dists[u] + 1;
                q.push(v);
            }
        }
    }
    vi distt(n, INF); distt[t] = 0;
    q.push(t);
    while(!q.empty()){
        int u = q.front(); q.pop();
        trav(v, adj[u]){
            if (distt[v] == INF){
                distt[v] = distt[u] + 1;
                q.push(v);
            }
        }
    }
    int ans = 0, d = dists[t];
    rep(i, 0, n){
        rep(j, i + 1, n){    
            if (mat[i][j] == 0 && (dists[i] + 1 + distt[j] >= d) && (dists[j] + 1 + distt[i] >= d)){
                ans++;
            }  
        }
    }
    cout << ans << '\n';
    return 0;
}
