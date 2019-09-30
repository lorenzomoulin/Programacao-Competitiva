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
    ll a[3],d;
    cin >> a[0] >> a[1] >> a[2] >>d ;
    sort(a, a + 3);
    ll res = 0;
    if (a[1] - a[0] < d)
        res += d - (a[1] - a[0]);
    if (a[2] - a[1] < d)
        res += d - (a[2] - a[1]);
    cout << res << '\n';
    return 0;
}
