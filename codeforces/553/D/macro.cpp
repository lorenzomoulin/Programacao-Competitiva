#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

bool comp1(pll a, pll b){
    
    return (a.first - a.second) > (b.first - b.second);
}

bool comp2(pll a, pll b){
    
    return (a.second - a.first) < (b.second - b.first);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    //pii ini[n];
    pll l[n], r[n];
    int i = 0, j = 0;
    for(i = j = 0; i + j < n;){
        ll a, b;
        cin >> a >> b;
        if (b > a)
            r[j] = pll(a, b), ++j;
        else {
            l[i] = pll(a, b);
            ++i;
        }
            
            
    }
    sort(l, l + i, comp1);
    sort(r, r + j, comp2);
    /*
    rep (k, 0, i){
        cout << l[k]. first << ", " << l[k].second << " ";
    }
    cout << "\n";
    rep(k, 0, j){
        cout << r[k].first << ", " << r[k].second << " ";
    }
    cout << "\n";*/
    ll res = 0;
    
    rep(k, 0, i){
        res += l[k].first*(k - 0) + l[k].second*(n - k - 1);
    }
    rep(k, 0, j){
        res += r[k].first*(k + i - 0) + r[k].second*(n - (k + i) - 1);
    }
    cout << res << "\n";
    
    
    
    return 0;
}
