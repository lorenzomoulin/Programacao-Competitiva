#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int,
    null_type,
    greater<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
statisticsTree;
#define rep(i, a, b) for(int i =a ; i < (b); i++)
#define INF 1000000000000000000LL
#define pb push_back
#define sz(x) (int)x.size()


typedef long long ll;

typedef pair<ll, ll > ii;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll x, y, h, v, res = 0;
    cin >> x >> y >> h >> v;
    vector<ii> horizontais(h), verticais(v);
    rep(i, 0, h){
        ll a, b;
        cin >> a >> b;
        horizontais[i] = ii(a, b);
    }
    sort(horizontais.begin(), horizontais.end());
    rep(i, 0, v){
        ll a, b;
        cin >> a >>b ;
        verticais[i] = ii(a, b);
    }
    sort(verticais.begin(), verticais.end());
    res += h + v + h*v + 1;
    
    statisticsTree ht, vt;
    
    for(auto &it: horizontais){
        res += ht.order_of_key(it.second);
        ht.insert(it.second);
    }
    for(auto &it: verticais){
        res += vt.order_of_key(it.second);
        vt.insert(it.second);
    }
    
    
    cout << res << "\n";
    return 0;
}
