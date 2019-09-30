#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);

    while (true){
        int n;    
        cin >> n;
        if(!n) break;
        map<ll, int> mapa;
        rep(i, 0, n) {
            ll a; cin >> a;
            map<ll, int>::iterator it = mapa.find(a);
            if (it != mapa.end())
                it->second++;
            else
                mapa.insert({a, 1});
        }
        trav(a, mapa){
            if (a.second & 1)
                cout << a.first << '\n';
        }
    }
    return 0;
}
