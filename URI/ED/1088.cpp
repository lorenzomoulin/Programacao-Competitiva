#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define rep(i, a, b) for(int i = a; i < (b); i++)
#define sz(x) (int)x.size()
#define pb push_back

using namespace std;


typedef vector<int> vi;

int merge_sort(vi &v){
    int inv = 0;
    if (sz(v) == 1) return 0;
    vi u1, u2;
    rep(i, 0, sz(v)/2)  u1.pb(v[i]);
    
    rep(i, sz(v)/2, sz(v))    u2.pb(v[i]);
    inv += merge_sort(u1);
    inv += merge_sort(u2);
    u1.pb(INF), u2.pb(INF);
    int ini1 = 0, ini2 = 0;
    rep(i, 0, sz(v)){
        if(u1[ini1] <= u2[ini2])
            v[i] = u1[ini1], ini1++;
        else
            v[i] = u2[ini2], ini2++, inv += sz(u1) - ini1 - 1;
    }
    return inv;
}

int main(){
    while(true){
        int n;
        cin >> n;
        if (!n)
            break;
        vi a(n);
        rep(i, 0, n){
            cin >> a[i];
        }
        int inv = merge_sort(a);
        cout << (inv % 2 ? "Marcelo" : "Carlos") << "\n";
    }
    return 0;
}
