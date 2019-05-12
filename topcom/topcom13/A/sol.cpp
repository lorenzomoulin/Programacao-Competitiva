#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll p, q, e, n, d, phi;

ll gcd(ll a, ll b, ll &x, ll &y){
    if(!b){
        x = 1; y = 0; return a;
    }
    ll g = gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

ll modinv(ll a, ll m){
    ll x, y;
    gcd(a, m, x, y);
    return (x % m + m) % m;
}

int main(){
    while(true){
        
        cin >> p >> q >> e;
        if (!p && !q && !e)
            break;
        n = p*q; phi = (p-1)*(q-1);
        d = modinv(e, phi);
        cout << n << " " << d << '\n';
    }
    return 0;
}
