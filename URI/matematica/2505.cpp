#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

ll mod_exp(ll n, ll b, ll m){
    if (b == 0) return 1;
    ll c = mod_exp(n, b / 2, m);
    c = (c * c) % m;
    if (b % 2)  c = (c * n) % m;
    return c;    
}

int main(){
    ll n; 
    while(cin >> n){
        ll nd = log10(n) + 1;
        ll m = 1;
        for(ll i = 1; i <= nd; i++)    m *= 10;
        ll resto = mod_exp(n, n, m);
        if (resto == n) cout << "SIM\n";
        else    cout << "NAO\n";
    }
    return 0;
}
