#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+9;
vi g[MAXN];
int vis[MAXN], n, m;
pii cst[MAXN];

void dfs(int u){
    vis[u] = 1;
    trav(v, g[u]){
        if (!vis[v])
            dfs(v);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m;
    rep(i, 0, n){
        cin >> cst[i].first;
        cst[i].second = i;
    }
    rep(i, 0, m){
        int x,y ;
        cin >> x >> y;
        x-- ,y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    sort(cst, cst + n);
    ll ans = 0;
    rep(i, 0, n){
        if (!vis[cst[i].second])
            dfs(cst[i].second), ans += cst[i].first;
    }
    cout << ans << '\n';
    return 0;
}
