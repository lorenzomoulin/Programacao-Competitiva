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
    int n, t;
    cin >> n >> t;
    if (t == 0) cout << n << '\n';
    else if (t == 1) cout << (n*(n-1)) << '\n';
    else {
        int res = 0;
        rep(i, 0, n - 2){
            rep (j, i + 2, n)
                res += j - i - 1;
        }
        cout << res << '\n';
    }
    return 0;
}
