#include <bits/stdc++.h>
#define M ((1LL << 31) - 1)
using namespace std;

typedef long long ll;

ll mod(ll a, ll b, ll m){
    if (!b) return 1LL;
    ll c = mod(a, b  / 2 , m);
    c = ( c * c) % m;
    if (b % 2 ) c = (c*a) % m;
    return c;
}

int main(){
    ll r;
    cin >> r;
    cout << mod(3LL, r, M) << "\n";
    return 0;
    
}
