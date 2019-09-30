#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 509
int  dp[MAXN][MAXN], n;
//0 nada
//1 preta
//2 branca
//3 ambos

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int p;
    
    memset(dp, 0, sizeof dp);
    cin >> n >> p;
    int qtd_pretas = p, qtd_brancas = p;
    rep(i, 0, p){
        int l, c;
        cin >> l >> c;
        dp[l][c] = 1;
    }
    rep(i, 0, p){
        int l, c;
        cin >> l >> c;
        dp[l][c] = 2;
    }
    
    rep(k, 2, n + 1){
        for(int i = 1; i <= n - k + 1; i++){
            for (int j = 1; j <= n - k + 1; j++){
                int a = dp[i][j], b = dp[i][j+1], c = dp[i+1][j], d = dp[i + 1][j+1];
                
                if (a == 3 || b == 3 || c == 3 || d == 3)
                    dp[i][j] = 3;
                else if ((a == 1 && (b == 1 || b == 0) && (c == 1 || c == 0) && (d == 1 || d == 0)) || (b == 1 && (a == 1 || a == 0) && (c == 1 || c == 0) && (d == 1 || d == 0)) ||
                            (c == 1 && (b == 1 || b == 0) && (a == 1 || a == 0) && (d == 1 || d == 0)) || (d == 1 && (b == 1 || b == 0) && (c == 1 || c == 0) && (a == 1 || a == 0))){
                    qtd_pretas++;
                    dp[i][j] = 1;
                }
                else if ((a == 2 && (b == 2 || b == 0) && (c == 2 || c == 0) && (d == 2 || d == 0)) || (b == 2 && (a == 2 || a == 0) && (c == 2 || c == 0) && (d == 2 || d == 0)) ||
                            (c == 2 && (b == 2 || b == 0) && (a == 2 || a == 0) && (d == 2 || d == 0)) || (d == 2 && (b == 2 || b == 0) && (c == 2 || c == 0) && (a == 2 || a == 0))){
                    qtd_brancas++;
                    dp[i][j] = 2;
                }
                else if ((a == 1 && (b == 2 || c == 2 || d == 2)) || (b == 1 && (a == 2 || c == 2 || d == 2)) || (c == 1 && (b == 2 || a == 2 || d == 2)) || (d == 1 && (b == 2 || c == 2 || a == 2)) )
                    dp[i][j] = 3;
                    
                else if ((a == 2 && (b == 1 || c == 1 || d == 1)) || (b == 2 && (a == 1 || c == 1 || d == 1)) || (c == 2 && (b == 1 || a == 1 || d == 1)) || (d == 2 && (b == 1 || c == 1 || a == 1)) )
                    dp[i][j] = 3;
            }
        }
    }
    
    cout << qtd_pretas << " " << qtd_brancas << '\n';
    
    return 0;
}
