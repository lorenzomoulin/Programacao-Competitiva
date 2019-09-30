    #include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e6;
vi rk, p, g[MAXN];
int vis[MAXN];
int getp(int v){
    if (v == p[v]) return v;
    return p[v] = getp(p[v]);
}

void join(int u, int v){
    u = getp(u);
    v = getp(v);
    if (rk[u] < rk[v]) swap(u, v);
    rk[u] += rk[v];
    p[v] = u;
}

void dfs(int u, int pai){
    vis[u] = 1;
    trav(a, g[u]){
        if (!vis[a])
            dfs(a, pai), join(a, pai);
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
        int k;
        cin >> k;
        if (k){
            int a;
            cin >> a;
            a--;
            rep(j, 0, k - 1){
                int b; cin >> b;
                b--;
                g[a].push_back(b);
                g[b].push_back(a);
            }
        }
    }
    rep(i, 0, n){
        if (!vis[i])
            dfs(i, i);
    }
    rep(i, 0, n){
        cout << rk[getp(i)] << ' ';
    }
    cout << '\n';
    return 0;
}
