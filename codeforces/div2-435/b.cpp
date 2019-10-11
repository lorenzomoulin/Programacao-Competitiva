#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2e5;
const int INF = 1e5;
int n;
vi adj[MAXN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    rep(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int tam = 0;
    vi clr(n, INF); clr[0] = 0;
    bool bpt = true;
    queue<int> q; q.push(0);
    while(!q.empty() && bpt){
        int u = q.front(); q.pop();
        trav(v, adj[u]){
            if (clr[v] == INF){
                clr[v] = 1 - clr[u];
                if (clr[v] == 1)tam++;
                q.push(v);
            }
            else if(clr[v] == clr[u]){
                bpt = false;
                break;
            }
        }
    }
    ll ans = 0;
    rep(i, 0, n){
        if (clr[i] == 0)
            ans += tam - sz(adj[i]);
    }
    cout << ans << '\n';
    return 0;
}
