#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int a[101], b[101], n, m;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    rep(i,0 , n) cin >> a[i];
    cin >> m;
    rep(i, 0, m) cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    cout << a[n-1] << " " << b[m-1] << '\n';
   
    return 0;
}
