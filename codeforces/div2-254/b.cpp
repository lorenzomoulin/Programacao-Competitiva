#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vi p, rk;
int getp(int v){
    if (v == p[v])  return v;
    return p[v] = getp(p[v]);
}

void join (int u, int v){
    u = getp(u);
    v = getp(v);
    if (u == v)
        return ;
    if (rk[u] < rk[v] ) swap(u, v);
    rk[u] += rk[v];
    p[v] = u; 
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
        a-- ,b--;
        join(a, b);
    }
    ll dgr = 1;
    rep(i, 0, n){
        if (getp(i) == i)
            dgr *= 1LL << (rk[i] - 1);
    }
    cout << dgr << '\n';
    return 0;
}
