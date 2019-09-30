#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define LSONE(n) (n & (-n))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T>
T modExp(T a, T b, T m) {
    if (b == 0) return (T)1;
    T c = modExp(a, b / 2, m);
    c = (c * c) % m;
    if (b % 2 != 0) c = (c*a) % m;
    return c;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    reverse(all(s));
    
    int m;
    cin >> m;
    vector<ll > res;
    rep(i, 0, m){
        ll mi;
        cin >> mi;
        ll mod = 0;
        rep(i, 0, sz(s)){
            if (s[i] == '1')
                mod += modExp(2LL, (ll)i, mi);
        }
        
        if(mod % mi == 0)
            res.push_back(mi);
    }
    if (sz(res)){
        sort(all(res));
        cout << res[0];
        rep(i, 1, sz(res)){
            cout <<' ' << res[i];
        }
    }
    else {
        cout << "Nenhum";
    }
    cout << '\n';
    return 0;
}
