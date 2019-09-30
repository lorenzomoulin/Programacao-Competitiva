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
    int t;
    cin >> t;
    while (t--){
        ll n, m, nmul, tamcycle, ncycles, res = 0, resto;
        cin >> n >> m;
        nmul = n / m;
        vi cycle;
        cycle.push_back(m % 10);
        int cur = (m + m) % 10;
        while (cur != cycle[0]) cycle.push_back(cur), cur = (cur + m) % 10;
        //trav(x, cycle)
          //  cout << x << ' ';
        tamcycle = sz (cycle);
        ncycles = nmul / tamcycle;
        rep (i, 0, tamcycle) res += (ll)cycle[i]*ncycles;
        resto = nmul % tamcycle;
        rep (i, 0, resto) res += (ll)cycle[i];
        cout << res << '\n';
    }
    return 0;
}
