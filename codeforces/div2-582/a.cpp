#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool check(int x){
    int d = log10(x) + 1;
    set<int> dig;
    while (x > 0){
        dig.insert(x%10);
        x/=10;
    }
    return sz(dig) == d;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int l, r;
    cin >> l >> r;
    rep(ans, l, r + 1){
        if (check(ans)){
            cout << ans << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
    return 0;
}
