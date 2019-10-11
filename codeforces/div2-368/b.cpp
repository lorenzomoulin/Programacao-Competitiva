#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
const ll INF = 1e17;
const int MAXN = 2e5;
vector<pii> adj[MAXN];
int n, m, k, st[MAXN], iss[MAXN];

ll dijkstra(){
    priority_queue< pii, vector<pii>, greater<pii>> pq;
    vi dist(n, INF);
    rep(i, 0, k)    dist[st[i]] = 0, pq.push(pii(0, st[i]));
    while(!pq.empty()){
        pii front = pq.top(); pq.pop(); 
        ll u = front.second; 
        ll d = front.first; 
        if (d > dist[u]) continue;
        trav(v, adj[u]){
            if (dist[u] + v.second < dist[v.first]){
                dist[v.first] = dist[u] + v.second;
                pq.push(pii(dist[v.first], v.first));
            }
        }
    }
    ll ans = INF;
    rep(i, 0, n){
        if (!iss[i])
            ans = min(ans, dist[i]);
    }
    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m >> k;
    rep(i, 0, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back(pii(b, c));
        adj[b].push_back(pii(a, c));
    }
    
    rep(i, 0, k){
        cin >> st[i];
        st[i]--;
        iss[st[i]] = 1;  
    }
    ll cst = dijkstra(); 
    if (cst == INF)
        cout << -1 << '\n';
    else
        cout << cst << '\n';
    return 0;
}
