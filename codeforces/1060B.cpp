#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll sum(ll n){
    ll r = 0;
    while(n){
        r += n % 10;
        n /= 10;
    }
    return r;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ll n, a = 0, res = 0;
    cin >> n;
    while(a <= n){
        
        a = a*10 + 9;
        if (a<=n)
            res += 9;
    }
    a = (a - 9) / 10;
    cout << sum (n - a) + res << '\n';
    return 0;
}
