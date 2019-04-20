#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cout << #x << ": " << x << "\n"
#define MOD 1000000007
typedef  long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll modmul(ll a, ll b){
    ll x = 0, y = a % MOD;
    while(b > 0){
        if(b % 2)   x = (x + y) % MOD;
        //debug(y);
        y = (y * 2LL) % MOD; b /= 2LL;
    }
    return x % MOD;
}

ll f(ll n){
    ll sum = 0;
    ll i = 0;
    ll qtdpar = 0, qtdimpar = 0;
    //O(lgn)
    while (sum <= n){
        sum += (1LL << i);
        if (i % 2)
            qtdpar += (1LL << i);
        else
            qtdimpar += (1LL << i);
        if (sum >= n)
            break;
        
        
        ++i;
    }

    if (i % 2)
        qtdpar -= (sum - n);
    else
        qtdimpar -= sum - n;
    //debug(qtdpar);
    //debug(qtdimpar);
    qtdpar = modmul(qtdpar, qtdpar + 1LL) ; 
    qtdimpar = modmul(qtdimpar, qtdimpar) ;
    ll res = (qtdpar  + qtdimpar ) % MOD;
    //cout << res << endl;
    
    //debug(qtdpar);
    //debug(qtdimpar);
    //debug(res);
    return res;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll l, r;
    cin >> l >> r;
    //cout << f(r) %MOD<< endl;
    //cout << f(l - 1LL) %MOD  << endl;
    ll res = f(r) - f(l-1);
    cout << (res >= 0 ? res : (res + MOD ) % MOD) << "\n";
    return 0;
}
