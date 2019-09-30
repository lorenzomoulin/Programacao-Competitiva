#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 109;
const int MAXR = 30009;
int w, l, dp[MAXN][MAXR];
pii win[MAXN], lose[MAXN];
bool cmp(pii a, pii b){
    return a.first + a.second > b.first + b.second;
}

int solve(int i, int r){
    if (i == l) 
        return 0;
    if (dp[i][r] != -1) return dp[i][r];
    
    int pega = 0, npega = solve(i+1, r);
    if (r - lose[i].first >= 0 && r + lose[i].second >= 0 )
        pega = 1 + solve(i+1, r + lose[i].second);    
    return dp[i][r] = max(pega, npega);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, r;
    cin >> n >> r;
    memset(dp, -1, sizeof dp);
    
    
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        if (b >= 0)
            win[w++] = pii(a, b);
        else
            lose[l++] = pii(a, b);
    }
    sort(win, win + w);
    sort(lose, lose + l, cmp);
    int res = 0;
    rep (i, 0, w){
        if (r < win[i].first){
            break;
        }
        r += win[i].second;
        res++;
        }
    
    res += solve(0, r);
    
    cout << res << '\n';
    return 0;
}
