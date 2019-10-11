#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 1e4;
int vis[MAXN], n, ans, p[MAXN];
vi g[MAXN];

void dfs(int u, int h){
    vis[u] = 1;
    ans = max(ans, h);
    trav(a, g[u]){
        if (!vis[a])
            dfs(a, h + 1);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    rep(i, 0, n){
        int a;
        cin >> a;
        if (a != -1)
            g[a].push_back(i+1);
        p[i+1] = a;
    }
    
    rep(i, 1, n + 1){
        if(!vis[i] && p[i] == -1){
            dfs(i, 1);            
        }
    }
    cout << ans << '\n';
    return 0;
}
