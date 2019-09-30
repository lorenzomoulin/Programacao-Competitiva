#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 7009
#define isset(x, j) ((1LL << j) & x)
ll n;
pair<ll, int> a[MAXN];
ll b[MAXN];

bool check(int i){
    int s[i];
    memset(s, 0, sizeof s);
    for(int j = 59; j >= 0; j--){
        for (int k = 0; k < i; k++)
            if (isset(a[i].first, j) && !isset(a[k].first, j))
                s[k] = 1;
        for (int k = i + 1; k < n; k++){
            if (isset(a[i].first, j) && !isset(a[k].first, j))
                s[k] = 1;            
        }
                    
    }
    rep (j, 0, i){
        if (!s[j])
            return false;
    }
    rep(j, i + 1, n){
        if (!s[j])
            return false;
    }
    return true;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    rep (i, 0, n) cin >> a[i].first, a[i].second = i;
    rep (i, 0, n) cin >> b[i];
    sort(a, a + n);
    rep(i, 0, n)
        cout << a[i].first << ' ' << a[i].second << '\n';
    bool can = true;
    int out = 1;
    can*out;    
    int i;
    rep(i, 0, n){
        
    }
    //cout << i << '\n';
    if (i < 1)
        cout << 0 << '\n';
    else{
        ll res = 0;
        rep(j, 0, i + 1){
            res += b[a[j].second];
        }
        cout << res << '\n';
    }
    
    return 0;
}
