#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
ll a[109];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    rep(i, 0, n){
        cin >> a[i];
    }
    sort(a, a + n);
    ll p = 0, i = 0;
    rep(j, 0, n){
        if (a[j] % 2)
            p++;
        else
            i++;
    }
    cout << min(p, i) << '\n';
    return 0;
}
