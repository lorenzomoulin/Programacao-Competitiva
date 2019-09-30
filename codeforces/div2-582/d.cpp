#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+9;
int n, m, g[MAXN];
vi adj[MAXN];
map<vi, int> mpvii;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m;
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int v = 0;
    rep(i, 0, n){
        sort(all(adj[i]));
        if (mpvii.find(adj[i]) != mpvii.end())
            g[i] = mpvii.at(adj[i]);
        else
            mpvii.insert({adj[i], ++v}), g[i] = v;
    }
    if (sz(mpvii) == 3){
        int v1 = 0, v2 = 0, v3 = 0;
        rep(i, 0, n){
            if(g[i] == 1) v1++;
            if (g[i] == 2) v2++;
            if (g[i] == 3) v3++;
        }
        trav(a, mpvii){
            if(a.second == 1){
                if (v1 + sz(a.first) != n){
                    cout << -1 << '\n';
                    return 0;
                }
            }
            if(a.second == 2){
                if (v2 + sz(a.first) != n){
                    cout << -1 << '\n';
                    return 0;
                }
            }
            if(a.second == 3){
                if (v3 + sz(a.first) != n){
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
        rep(i, 0, n)
            cout << g[i] << ' ';
        cout << '\n';
    }
    else
        cout << -1 << '\n';
    return 0;
}
