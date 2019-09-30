#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define EPS 1e-3
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2e5 + 9;
int n, g;

struct pt{
    int id, c, g;
    double cb;
};

bool cmp(pt a, pt b){
    return a.cb > b.cb;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    while (cin >> n >> g){
        vector<pt> a;
        bool u[n];
        memset(u, 0, sizeof u);
        int res = 0;
        rep(i, 0, n){
            int s, t;
            cin >> s >> t;
            pt v, e;
            if (s > t) res += 3;
            else if (s == t) {
                res++;
                v = {i, 1, 2, 2.0};
                a.pb(v);
            }
            else{
                v = {i, t - s + 1, 3, 3.0/(t - s + 1)};
                e = {i, t - s, 1, 1.0/(t -s)};
                a.pb(v);
                a.pb(e);
            }
        }
        sort(all(a), cmp);
        
        for (int i = 0; i < sz(a) && g > 0; i++){
            if (!u[a[i].id] && g - a[i].c >= 0){ 
                res += a[i].g;
                g -= a[i].c;
                u[a[i].id] = true;
            }
        }
        cout << res << '\n';
    }
    return 0;
}
