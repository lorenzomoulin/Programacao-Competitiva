#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5 +9;
int pt[MAXN];
vi p, rk;

int getp(int v){
    if (v == p[v])  return v;
    return p[v] = getp(p[v]);
}

void join(int u, int v ){
    u = getp(u);
    v = getp(v);
    if (u == v)
        return;
    if (rk[u] < rk[v])  swap(u, v);
    pt[u] += pt[v];
    rk[u] += rk[v];
    p[v] = u;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, m;
    while(true){
        cin >> n >> m;
        if (n + m == 0) break;
        p = rk = vi(n ,1);
        iota(all(p), 0);
        rep(i, 0, n) cin >> pt[i];
        int ans = 0;
        while(m--){
            int q, a, b;
            cin >> q >> a >> b;
            a--, b--;
            if(q == 1)  join(a, b);
            else {
                if (getp(a) == getp(0)){
                    ans += pt[getp(a)] > pt[getp(b)];
                }
                else if (getp(b) == getp(0)){
                    ans += pt[getp(b)] > pt[getp(a)];
                }
                
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
