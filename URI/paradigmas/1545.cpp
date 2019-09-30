#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 10005
ll n, dp[2][MAXN], v[MAXN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    while (cin >> n){
        rep(i, 0, n) cin >> v[i];
        memset(dp, 0, sizeof dp);
        for (int l = n - 1; l >= 0; l--){
            for (int r = l; r < n; r++){
                int k = l&1;
                if ((l + r) & 1)    dp[k][r] = max(v[l] + dp[!k][r], v[r]+dp[k][r-1]);
                else                dp[k][r] = max(dp[!k][r], dp[k][r-1]);
            }
        }
        cout << dp[n&1][n-1] << '\n';
    }
    return 0;
}
