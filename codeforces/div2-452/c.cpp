#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n, s = 0, t = 0, g[60010];
    cin >> n;
    s = n*(n+1)/2;
    if (s & 1)
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    s /= 2;
    for(ll i = n; i > 0; i--){
        if (s - i >= 0)
            g[t++] = i, s -= i;
        
    }
    cout << t;
    rep(i, 0, t){
        cout << ' ' << g[i];
    }
    cout << '\n';
    return 0;
}
