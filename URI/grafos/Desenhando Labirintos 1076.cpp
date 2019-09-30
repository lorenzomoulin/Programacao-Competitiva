#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXV 50

int grafo[MAXV][MAXV], vis[MAXV], v, a, cont;

void dfs(int u){
    vis[u] = 1;
    //cout << "visited: " << u << '\n';
    rep(j, 0, v){
        if(grafo[u][j] && !vis[j]){
            dfs(j);
            cont++;
        }
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int tc; cin >> tc;
    while (tc--)
    {
        int n; cin >> n >> v >> a;
        memset(grafo, 0, sizeof grafo);
        memset(vis, 0, sizeof vis);
        cont = 1;
        rep(i, 0, a){
            int x, y; cin >> x >> y;
            if (!grafo[x][y])
            {
                grafo[x][y] = grafo[y][x] = 1;
            }
        }
        dfs(n);
        cout << (cont - 1 )*2 << '\n';
    }
    

    return 0;
}
