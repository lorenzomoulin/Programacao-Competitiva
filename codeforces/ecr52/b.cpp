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
    ll n, m;
    cin >> n >> m;
    cout << (n - 2*m >= 0 ? n - 2*m : 0) << ' ';
    ll ans = (1 + sqrt(1 + 8*m)) / 2.0;
    //cout << ans << '\n';
    if (m + 1 <= n)
        ans = max(m+1, ans);
    cout << n - ans << '\n'; 
    return 0;
}
