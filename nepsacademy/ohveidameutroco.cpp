#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 1009
int n, m, dp[MAXN][MAXN], a[MAXN];

int solve(int i, int sum){
    if (i == n || sum < 0) return 0;
    if (dp[i][sum] != -1) return dp[i][sum];
    if (sum == 0) return dp[i][sum] = 1;
    return dp[i][sum] = solve(i, sum - a[i]) || solve(i + 1, sum);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    rep(i, 0, n) cin >> a[i];
    cout << (solve(0, m) ? 'S' : 'N') << '\n';    
    return 0;
}
