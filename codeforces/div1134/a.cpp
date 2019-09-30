#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 109
vi p, rk;
int res;
pii a[MAXN];
int getp(int v){
    if (v == p[v]) return v;
    return p[v] = getp(p[v]);
}

void join(int u, int v){
    u = getp(u);
    v = getp(v);
    if (rk[u] < rk[v])  swap(u, v);
    //if (a[u].first == a[v].first || a[u].second == a[v].second){
        //res++;
    rk[u] += rk[v];
    
    p[v] = u;
    //}
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    
    p = rk = vi(n, 1);
    iota(all(p), 0);
    rep(i, 0, n) cin >> a[i].first >> a[i].second;
    rep(i, 0, n){
        rep(j, i, n){
            if (getp(i) != getp(j) && a[i].first == a[j].first || a[i].second == a[j].second)
                join(i, j);
        }
    }
    set<int> s;
    rep(i, 0, n)
        s.insert(getp(i));
    cout << sz(s) - 1 << '\n';
    return 0;
}
