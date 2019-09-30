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

int n, k, d, dp[MAXN];

int solve(int x, bool has){
    cout << "has = " << has << '\n';
    if (x == n && has)
        return 1;
    if (x == n && !has)
        return 0;
    if (x > n)
        return 0;
    if (dp[x] != -1)
        return dp[x];
   
    int res = 0;
    rep(i, 1, k + 1){
        cout << x << ": " << i << ", res = " << res << ", has = " << has << '\n';
        if (has){
            res += solve(x + i, true);
        }
        else if(!has && i >= d){
            res += solve(x + i, true);
        }
        else if (!has && i < d){
            res += solve(x + i, false);
        }
    }
    return dp[x] = res;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof dp);
    cin >> n >> k >> d;
    cout << solve(0, 0) << '\n'; 
    return 0;
}
