#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 5e3 + 9;
int dp[maxn][maxn], n;
string s;

int solve(int i, int j){
    if (i == n || j == n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] != s[j]) return 0;
    return dp[i][j] = min(j - i, 1 + solve(i + 1, j + 1));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> s;
    memset(dp, -1, sizeof dp);
    int res = 0;
    rep(i, 0, n){
        rep(j, i + 1 ,n){
            res = max(res, solve(i, j));
        }
    }
    cout << res << '\n';
    return 0;
}
