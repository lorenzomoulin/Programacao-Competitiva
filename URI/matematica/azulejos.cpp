#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){  return b == 0? a : gcd(b, a % b);}

ll lcm(ll a, ll b){
    return a*(b/gcd(a, b));
}

int main(){
    ll n, a, b;
    while(true){
        cin >> n >> a >> b;
        if (!n && !a && !b)
            break;
        ll res = n/a + n/b - n/lcm(a, b);
        cout << res << "\n";
    }
    return 0;
}
