#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 2e5 + 9;

vi p, rk, g[MAXN];
int vis[MAXN], edges;
bool cycle;
int getp(int v){
    if (v == p[v]) return v;
    return p[v] = getp(p[v]);
}

void join(int u, int v){
    u = getp(u);
    v = getp(v);
    if (rk[u] < rk[v])  swap(u, v);
    rk[u] += rk[v];
    p[v] = u;
}

void dfs(int u, int pai){
    vis[u] = 1;
    if (sz(g[u]) != 2) cycle = false;
    trav(a, g[u]){
        if (!vis[a])
            dfs(a, u);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    p = rk = vi(n, 1);
    iota(all(p), 0);
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        if (getp(a) != getp(b))
            join(a, b);
    }
    int ans = 0;
    rep(i,0 , n){
        cycle = true;
        edges = 0;
        if (i == getp(i)){
            dfs(i, i);
            if (cycle)
                ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}
