#include <bits/stdc++.h>
#define INF 1000000000000000000LL
#define rep(i, a, b) for(long long i = a; i < (b); i++)
#define sz(x) (long long )x.size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<ll> vll;


ll merge_sort(vll &v){
    ll inv = 0;
    if (sz(v) == 1) return 0;
    vll u1, u2;
    rep(i, 0, sz(v)/2)  u1.pb(v[i]);
    
    rep(i, sz(v)/2, sz(v))    u2.pb(v[i]);
    inv += merge_sort(u1);
    inv += merge_sort(u2);
    u1.pb(INF), u2.pb(INF);
    ll ini1 = 0, ini2 = 0;
    rep(i, 0, sz(v)){
        if(u2[ini2] < u1[ini1])
            v[i] = u2[ini2], ini2++;
        else
            v[i] = u1[ini1], ini1++, inv += sz(u2) - ini2 - 1;
    }
    return inv;
}

int main(){
    ll n;
    cin >> n;
    vll a(n);
    
    rep(i, 0, n){
        ll x, y;
        cin >> x >> y;
        a[i] = x*x + y*y;
    }
    //for(auto &b : a)
        //cout << b << " ";
    //cout << endl;
    cout << merge_sort(a) << "\n";
    
    return 0;
}
