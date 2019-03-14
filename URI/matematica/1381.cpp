#include <iostream>
#include <cmath>

using namespace std;

#define P 1300031LL



typedef long long ll;

ll pd[3000001];
ll x;
ll y;
ll d;

void calcula(){
    pd[0] = 1;
    
    for (ll i = 1; i <= 3000000; i++)
        pd[i] = (pd[i-1]%P * i%P) % P;
    
}

void extendedEuclid(ll a, ll b) {
    if (b == 0) { x = 1; y = 0; d = a; return; } // base case
    extendedEuclid(b, a % b); // similar as the original gcd
    ll x1 = y;
    ll y1 = x - (a / b) * y;
    x = x1;
    y = y1;
    
}

int main(){
    
    int t;
    cin >> t;
    calcula();
    while(t--){
        ll n, c;
        cin >> n >> c;
        ll inv = (pd[c]*pd[n-1])%P;
        extendedEuclid(inv, P);
        if ( x < 0 ) x += P ;
        ll num = (pd[n+c-1]*x)%P;
        cout << num << endl;
    } 
    return 0;
}
