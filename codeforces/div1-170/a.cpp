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
vi p, rk, e[MAXN];

int getp(int v){
    if (v == p[v])  return v;
    return p[v] = getp(p[v]);
}

void join (int u, int v){
    u =getp(u);
    v = getp(v);
    if (rk[u] < rk[v])  swap(u, v);
    rk[u] += rk[v];
    p[v] = u;
}

bool check(int u, int v){
    trav(a, e[u]){
        trav(b, e[v]){
            if (a == b) 
                return true;
        }
    }
    
    return false;
}   

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, m ,res = 0;
    cin >> n >> m;
    p = rk = vi(n, 1);
    iota(all(p), 0);
    
    rep(i, 0, n){
        int a;
        cin >> a;
        if (!a)
            res++;
        rep(j, 0, a){
            int b;
            cin >> b;
            e[i].push_back(b);
        }                
    }
    bool x = false;
    rep(i, 0, n){
        if (sz(e[i]))
            x = true;
    }
    if (!x){
        cout << n << '\n';
        return 0;
    }
    rep(i, 0, n){
        rep(j, i + 1, n){
            if (getp(i) != getp(j) && check(i, j)){
                join(i, j);
            }
        }
    }    
    
    rep(i,0 , n){
        rep(j, i + 1, n){
            if (sz(e[i])&&sz(e[j])){
                if (getp(i)  != getp(j)){
                    res++;
                    join(i, j);
                }
            }
        }
    }
    cout << res << '\n';
    return 0;
}
