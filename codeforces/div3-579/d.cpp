#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 2e5 + 9;
string s, t;
int n, m, pref[maxn], rg[maxn];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    cin >> s >> t;
    n = sz(s);
    m = sz(t);
    int k = m - 1;
    for(int i = m - 1; i >= 0; i--){
       int pos = n - 1;
		if (i + 1 < m) pos = rg[i + 1] - 1;
		while (s[pos] != t[i]) --pos;
		rg[i] = pos;
    }
    k = 0;
    rep(i, 1, n + 1){
        if (s[i-1] == t[k] && k < m){
            k++, pref[i] = k;
        }
        pref[i] = k;
    }
    int res = 0;
    rep(i, 0, n + 1){
        if (pref[i] == 0)
            res = max(res, rg[0] - i);
        
        else{
            if (pref[i] == m)
                res = max(res, n - i);
            else
                res = max(res, rg[pref[i]] - i);
       
        }
    }
    
    cout << res << '\n';
    return 0;
}
