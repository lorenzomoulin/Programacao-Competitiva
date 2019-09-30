#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cout << #x << "=" << x << '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e5+9;

int n, k;

vi adj[MAXN];
vector<pii> folha;
int vis[MAXN], p[MAXN], h[MAXN], usado[MAXN], vis2[MAXN];
pii max_h[MAXN];

void dfs(int u, int alt){
    vis[u] = 1;
    h[u] = alt;
    if (sz(adj[u]) == 1 && u != 1)
        folha.push_back(pii(-alt, u));
    trav(a, adj[u]){
        if (!vis[a]){
            p[a] = u;
            dfs(a, alt + 1);    
        }
    }
    return ;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    memset(vis, 0 ,sizeof vis);
    cin >> n >> k;
    rep(i, 2 , n + 1){
        int a; cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(1, 1);
    p[1] = 1;
    sort(all(folha));
    vi res;
    trav(a, folha){
        int u = a.second;
        int sum = 0;
        while (!vis2[u]){
            sum++;
            vis2[u] = 1;
            u = p[u];
        }
        res.push_back(sum);
    }
    sort(res.rbegin(), res.rend());
    int sum = 0;
    for(int i = 0; i < k && i < sz(res); i++){
        sum += res[i];
    }
    cout << sum << '\n';
    return 0;
}
