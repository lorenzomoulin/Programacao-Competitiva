#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi rk, p;

int getp(int v){
    if (v == p[v]) return v;
    return p[v] = getp(p[v]);
}

ll res;

void merge(int u, int v){
    u = getp(u);
    v = getp(v);
    if (rk[u] < rk[v]) swap(u, v);
    res += (ll)rk[u]*rk[v]*1ll;
    rk[u] += rk[v];
    p[v] = u;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    p = rk = vi(n,1);
    iota(all(p), 0);
    vector<pair<int, pii>> e(n-1);
    rep(i, 0, n-1){
        cin >> e[i].second.first >> e[i].second.second >> e[i].first;
        --e[i].second.first;
        --e[i].second.second;
    }
    vector<pii> q(m);
    vector<ll> ans(m);
    rep(i, 0, m){
        cin >> q[i].first;
        q[i].second = i;
    }
    sort(all(e));
    sort(all(q));
    
    int pos = 0;
    rep(i, 0, m){
        while (pos < n - 1 && e[pos].first <= q[i].first){
            int u = e[pos].second.first;
            int v = e[pos].second.second;
            merge(u, v);
            ++pos;
        }
        ans[q[i].second] = res;
    }
    rep(i, 0, m){
        cout << ans[i] << " ";
    }
    cout << '\n';
    return 0;
}
