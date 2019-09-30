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
    int n;
    cin >> n;
    pii a[n];
    rep(i, 0, n) cin >> a[i].first, a[i].second = i+1;
    sort(a, a + n);
    rep(i, 0, n-1)
        cout << a[i].second << ' ';
    cout << a[n-1].second << '\n';
    return 0;
}
