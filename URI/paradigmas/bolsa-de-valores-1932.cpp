#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 200005
int n, c, pd[MAXN][2], valor[MAXN];

int solve(int dia, bool possui){
    if (pd[dia][possui] != -1)
        return pd[dia][possui];
    if (dia == n)
        return pd[dia][possui] = 0;
    if (possui){
        return pd[dia][possui] = max(valor[dia] + solve(dia + 1, !possui), solve(dia + 1, possui));
    }
    return pd[dia][possui] = max(solve(dia + 1, possui), -(valor[dia] + c) + solve(dia + 1, !possui));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    rep (i, 0, n)
        cin >> valor[i];
    memset(pd, -1, sizeof pd);
    cout << solve(0, false) << '\n';    
    
    return 0;
}
