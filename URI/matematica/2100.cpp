#include <iostream>
using namespace std;
#define MOD 1300031
typedef long long ll;

ll fat[4001];

void calc(){
    fat[0] = 1;
    for (int i = 1; i <= 4000; i++){
        fat[i] = ((fat[i - 1] ) * (i) ) % MOD;
    }
}

ll ext_gcd(ll a, ll b, ll& x, ll& y){
    if (b == 0){
        x = 1; y = 0; return a; 
    }
    else{
        ll g = ext_gcd(b, a % b, y, x);
        y -= (a / b )* x; return g; 
    }
}

ll inv(ll a){
    ll x, y, m = MOD;
    ext_gcd(a, m, x, y);
    return (x % MOD + MOD) % MOD;
}

ll exp_mod(ll a, ll b){
    if (b == 0) return 1;
    ll c = exp_mod(a, b / 2);
    c  = (c * c) % MOD;
    if (b % 2)  c = (c * a) % MOD;
    return c;
}

int main(){
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    calc();
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll exp = exp_mod(2, m);
        cout << (exp*((fat[n - m] * inv(fat[n - 2*m])) % MOD)) % MOD << endl;
    }
    return 0;
}
