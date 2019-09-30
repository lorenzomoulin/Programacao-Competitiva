#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll MAXM = 1e3+9;
const ll MAXN = 13;
const ll inf = 1e9;
ll n, m, a[MAXM], b[MAXM], dp[MAXM][1<<MAXN], c[MAXM][MAXN];

ll solve(int box, int mask){
    if (dp[box][mask] != -1) return dp[box][mask];
    if (box == m){
        //cout << mask  << " " << (1<<n)<< '\n';
        if (mask != (1 << n)  -1 )
            return inf;
        return 0;
    }
    int tmask = 0;
    rep(i, 0, b[box]){
        tmask |= (1 << (c[box][i]-1));
    }
    return dp[box][mask] = min(solve(box+1, mask), a[box] + solve(box+1, mask | tmask));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    memset(dp , -1, sizeof dp);
    cin >> n >> m;
    rep(i, 0, m){
        cin >> a[i] >> b[i];
        rep(j, 0, b[i])
            cin >> c[i][j]; 
    }
    int ans = solve(0, 0);
    cout << (ans == inf ? -1: ans)  << '\n';
    return 0;
}
