#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;

typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    while (true){
        int n;
        cin >> n;
        if (!n) break;
        vector<pii> compra, vende;
        rep(i, 0, n){
            ll a;
            cin >> a;
            (a >=0) ? compra.push_back(pii(a, i)) : vende.push_back(pii(a, i));
        
        }
        ll cost = 0;
        for (int i = 0, j = 0; i < sz(compra) && j < sz(vende);){
            if (-vende[j].first < compra[i].first)
                cost += -1*vende[j].first*abs(vende[j].second - compra[i].second), compra[i].first += vende[j].first, vende[j].first = 0;
            else
                cost += compra[i].first*abs(vende[j].second - compra[i].second), vende[j].first += compra[i].first, compra[i].first = 0;
           /* cout << "compra\ni: " << i << '\n';
            trav(a, compra)
                cout << a.first << " " << a.second << '\n';
            cout << "vende\nj: " << j << '\n';
            trav(e, vende)
                cout << e.first << " " << e.second << '\n';*/
            if (!vende[j].first)
                j++;
            if (!compra[i].first)
                i++;
        }
        cout << cost << '\n';
    }
   return 0;
}
