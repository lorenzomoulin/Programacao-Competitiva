#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 100009
#define MAXT 59
#define MOD 1000000007
int t, m, n, dp[MAXN][MAXT];

int solve(int dificuldade, int tempo){

    if (dp[dificuldade][tempo] != -1)
        return dp[dificuldade][tempo];
    if (tempo == 1)
        return dp[dificuldade][tempo] = 1;
    if (dificuldade < m || dificuldade > n)
        return dp[dificuldade][tempo] = 0;
    int esq = 0, dir = 0;
    if (dificuldade - 1 >= m)
        esq = (solve(dificuldade - 1, tempo - 1)) % MOD;
    if (dificuldade + 1 <= n)
        dir = (solve(dificuldade + 1, tempo - 1)) % MOD;
    return dp[dificuldade][tempo] = (esq + dir) % MOD;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> t >> m >> n;
    int res = 0;
    rep(i, m, n + 1){
        res = (res + solve(i, t)) % MOD;
    }
    cout << res << '\n';
    return 0;
}
