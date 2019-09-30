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
    int n; cin >> n;
    set<pii> res;
    bool flag = false;
    rep(i, 0, n){
        int x, y;
        cin >> x >> y;
        if (res.find(pii(x, y)) != res.end())
            flag = true;
        res.insert(pii(x, y));
    }
    cout << flag << '\n';
    return 0;
}
