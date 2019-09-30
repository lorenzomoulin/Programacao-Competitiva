#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxa = 2e5 + 9;
const int inf = 0x3f3f3f3f;

pair<int, pii> dat[maxa];
int seen[maxa];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, k;
    cin >> n >> k;
    int a[n], gt = 0;
    rep (i, 0, n){
        cin >> a[i]; 
        gt = max(gt, a[i]);
    }
    sort(a, a + n);
    pii val[gt + 1];
    rep(i, 0, n){
        int x = a[i], qt = 0;
        while (x > 0){
            if (val[x].first < k)
                val[x].first++, val[x].second += qt;
            qt++;
            x /= 2;
        }
        if (val[x].first < k)
            val[x].first++, val[x].second += qt;
    }
   
    int res = inf;
    rep(i, 0, gt + 1){
        if (val[i].first >= k)
            res = min(res, val[i].second);
    }
    cout << res << '\n';
    return 0;
}
