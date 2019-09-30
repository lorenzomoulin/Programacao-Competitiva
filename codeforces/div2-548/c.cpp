#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const ll mod = 1e9+7;

ll fexp(ll a, ll b, ll m = mod){
    ll r = 1;
    for(a %= m; b; b>>=1, a=(a*a)%m) if (b&1) r = (r*a)%m;
    return r;
}

vi rk, p;
int getp(int v){
    if (v == p[v])  return v;
    return p[v] = getp(p[v]);
}

void join(int u, int v){
    u = getp(u);
    v = getp(v);
    if (u == v)
        return;
    if (rk[u] < rk[v])  swap(u, v);
    
    rk[u] += rk[v];
    p[v] = u;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    rk = p = vi(n, 1);
    iota(all(p), 0);
    rep(i, 0, n-1){
        int x,y,z;
        cin >> x >> y >>z;
        x--, y--;
        if(!z)
            join(x,y);
    }
    ll ans = fexp(n, k);    
    rep(i, 0, n){
        if (getp(i) == i)
            ans = (ans -( fexp(rk[i], k) - rk[i])) % mod;
    }
    ans = (ans - n) % mod;
    if (ans < 0)
        ans += mod;
    cout << ans << '\n';
    return 0;
}
