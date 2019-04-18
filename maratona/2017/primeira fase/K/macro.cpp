#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXN 10000009

double modexp (double a, double b, double m){
    if (b == 0) return 1LL;
    double c = modexp(a, b / 2, m);
    c = ((ll)(c * c)) % (ll)m;
    if (((  ll)b) % 2 != 0)
        c = ((ll)(c * a)) % (ll)m;
    return c;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    double a, b, n, k;
    cin >> a >> b >> n >>k;
    if (k == 1)
        cout << modexp((a + sqrt(b)), n, 10LL) << "\n";
    else if (k == 2)
        cout << modexp((a + sqrt(b)), n, 100LL) << "\n";
    else if (k == 3)
        cout << modexp((a + sqrt(b)), n, 1000LL) << "\n";
    else if (k == 4)
        cout << modexp((a + sqrt(b)), n, 10000LL) << "\n";
    return 0;
}
