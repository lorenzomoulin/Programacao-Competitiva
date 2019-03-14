#include <iostream>
using namespace std;
typedef long long ll;

ll phi(ll n){
    ll i = 2, ans = n;
    while (i * i <= n){
        if (n % i == 0) ans -= ans/i;
        while(n % i == 0)   n /= i;
        i++;
    }
    if (n != 1) ans -= ans/n;
    return ans;
}

ll expmod(ll a, ll b, ll m){
    if (b == 0) return 1;
    ll c = expmod(a, b / 2, m);
    c = (c * c) % m;
    if (b % 2)  c = (c * a) % m;
    return c;
}

ll extgcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1; y = 0; return a;
    }
    ll g = extgcd(b, a % b, y, x);
    y -= a / b * x; 
    return g;
}

ll modinv(ll a, ll m){
    ll x, y;
    extgcd(a, m, x, y);
    return (x % m + m) % m;
}

int main(){
    ll n, e, c;
    cin >> n >> e >> c;
    ll phi_n = phi(n);
    ll d = modinv(e, phi_n);
    ll m = expmod(c, d, n);
    cout << m << endl;
    return 0;
}
