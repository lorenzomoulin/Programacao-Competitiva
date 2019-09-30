#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MAXN = 1e5 + 9;
vi rk, p;
ll cst[MAXN];

int getp(int v){
    if (v == p[v])  return v;
    return p[v] = getp(p[v]);
}

void join(int u, int v){
    u = getp(u);
    v = getp(v);
    if (u == v) return;
    if (rk[u] < rk[v])  swap(u, v);
    rk[u] += rk[v];
    cst[u] = min(cst[u], cst[v]);
    p[v] = u;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, k, m;
    cin >> n >> k >> m;
    string st[n];
    map<string, int> msi;
    p = rk = vi(n, 1);
    iota(all(p), 0);
    rep(i, 0, n){
        cin >> st[i];
        msi.insert({st[i], i});
    }
    
    rep(i,0 , n) cin >> cst[i];
    rep(i, 0, k){
        int a, b;
        cin >> a >> b;
        b--;
        rep(j, 1, a){
            int c; 
            cin >> c;
            c--;
            join(b, c);
        }
    }
    ll res = 0;
    rep(i, 0, m){
        string s;
        cin >> s;
        res += cst[getp(msi[s])];
    }
    cout << res << '\n';
    return 0;
}
