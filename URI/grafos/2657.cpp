#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e4 + 9;
int maior[MAXN], pt[MAXN];

vi rk, p;
int getp(int v){
    if (v == p[v])  return v;
    return p[v] = getp(p[v]);
}

void join(int u, int v){
    u = getp(u);
    v = getp(v);
    if (u == v) return ;
    if (rk[u] < rk[v]) swap(u,v);
    maior[u] = max(maior[u], maior[v]);
    rk[u] += rk[v];
    p[v] = u;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, m, q;
    cin >> n >> m >> q;
    p = rk = vi(n, 1);
    iota(all(p), 0);
    map<string, int> msp;
    int pt[n];
    rep(i, 0, n){
        string s;
        int np;
        cin >> s >> np;
        msp.insert({s, i}); 
        pt[i] = np;
        maior[i] = np;
    }
    rep(i, 0, m){
        string a, b;
        cin >> a >> b;
        join(msp[a], msp[b]);
    }
    rep(i, 0, q){
        string s;
        cin >> s;
        int pos = msp[s];
        if (rk[getp(pos)] == 1){ //1
            cout << "S\n";
        }
        else if (maior[getp(pos)] <= 5){ // 2
            cout << "S\n";
        }
        else if (pt[pos] >= 5) //3
            cout << "S\n";
        else
            cout << "N\n";
    }
    
    return 0;
}
