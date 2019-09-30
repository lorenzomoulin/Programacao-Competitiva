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

void join(int u, int v){
    u = getp(u);
    v = getp(v);
    if (u == v) return ;
    if (rk[u] < rk[v])  swap(u, v);
    rk[u]+=rk[v];
    p[v] = u;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, q;
    cin >> n >> q;
    rk = p = vi(n, 1);
    iota(all(p), 0);
    while (q--){
        char c;
        int i, j;
        cin >> c >> i >> j;
        i--, j--;
        if (c == 'C')
            getp(i) == getp(j) ? cout << "S\n" : cout << "N\n";
        else
            join(i, j);
    }
    return 0;
}
