#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXM 1009
#define MAXP (1 << 11)
// tuple <ini, fim, qtd, palco>
vector<tuple<int, int, int, int>> shows;
int dp[MAXM][MAXP], n, p, to[MAXM];

bool comp(tuple<int, int, int, int> tp, int v){
    return get<0>(tp) < v;
}

int calc(int show, int bitmask){
    if (dp[show][bitmask] != -1)    return dp[show][bitmask];
    if (show == n)  return dp[show][bitmask] = (bitmask == (1 << p) - 1) ? 0 : -2; 
    int pega = calc(to[show], bitmask | (1 << get<3>(shows[show]))), npega = calc(show + 1, bitmask);
    if ( pega != -2){
        return dp[show][bitmask] = max(get<2>(shows[show]) + pega, npega);   
    }
    return dp[show][bitmask] = max(pega, npega); 
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> p;
    memset(dp, -1, sizeof dp);
    rep(i, 0, p){
        int x, ini, fim, qtd;
        cin >> x;
        rep(j, 0, x){
            cin >> ini >> fim >> qtd;
            shows.push_back(make_tuple(ini, fim, qtd, i));
        }
    }
    sort(all(shows));
    n = sz(shows);
    rep(i, 0, n){
        bool flag = false;
        auto it = lower_bound(all(shows), get<1>(shows[i]), comp);
        if ( it != shows.end()) to[i] = it - shows.begin();
        else to[i] = n;
    }
    cout << (calc(0, 0) < 0 ? -1 : calc(0, 0)) << '\n';
    return 0;
}
