#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXR 110
#define MAXK 50000
vi adj[MAXR];
bool dp[MAXR][MAXK];
vi lista;
int r, k;

void calc(){
    rep(i, 0, r)
        dp[i][0] = true;
    rep(i, 1, k + 1){
        if (lista[0] == i)
            dp[0][i] = true;
        else
            dp[0][i] = false;
    }
    rep(i, 1, r){
        rep(j, 1, k + 1){
            if (j < lista[i])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j - lista[i]];
        }
    }
    /*rep(i, 0, r){
        rep(j, 0, k+1)
            cout << dp[i][j] << ' ';
        cout << '\n';
    }*/
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    while (cin >> r >> k){
        rep(i, 0, MAXR)
            adj[i].clear();
        lista.clear();
        
        
        rep(i, 0, k){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //lista[0] = 2, lista[1] = 3, lista[2] = 7, lista[3] = 8, lista[4] = 10;
        rep(i, 1, r + 1){
            lista.push_back(adj[i].size());
        }
        //r = 5, k = 11;
        calc();
        cout << (dp[r - 1][k] ? 'S' : 'N') << '\n';
    }
    return 0;
}
