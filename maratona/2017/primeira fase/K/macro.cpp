#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

ld f(ld x, int N){
    //cout << (ll)x << endl;
    ld dec = x - (ll)x;
    ll i = (ll)x;
    //cout << i << 
    i = i % 10000;
    x = i;
    x += dec;
    x = x * x;
    dec = x - (ll)x;
    i = (ll)x;
    //cout << i << 
    i = i % 10000;
    x = i;
    x += dec;
    //cout << N << " "<< x  << endl;
    if (N == 1)
        return x;
    if (N % 2)
        return sqrt(x)*f(x, (N - 1) / 2);
    return f(x, N/2);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    ld a, b, n;int k;
    cin >> a >> b >> n >>k;
    cout << f(a + sqrt(b), n) << endl;
    ll res = f(a + sqrt(b), n);
    
    if (k == 1)
        cout << res % 10 << "\n";
    else if (k == 2)
        cout << res % 100 << "\n";
    else if (k == 3)
        cout << res % 1000 << "\n";
    else if (k == 4)
        cout << res % 10000 << "\n";
    return 0;
}
