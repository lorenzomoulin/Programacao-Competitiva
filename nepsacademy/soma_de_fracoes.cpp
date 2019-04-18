#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){  return b == 0? a : gcd(b, a % b);}

int main(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll num = a*d + b*c;
    ll den = b*d;
    cout << (num / gcd(num, den)) << " " << (den / gcd(num, den)) << "\n";
    return 0;
}
