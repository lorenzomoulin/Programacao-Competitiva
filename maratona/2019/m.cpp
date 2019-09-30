#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cout << #x << "=" << x << '\n'
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 9; 

int n, c, t, sacos[maxn];

bool check(int x){
    int k = 0, temp = 0;
    rep(i, 0, n){
        int cost = ((temp + sacos[i]) / t) + ((temp + sacos[i]) % t > 0);
        
        if ((cost > x) && (k == c - 1))
            return false;
        else if (cost > x){
            temp = 0;
            k++;
            i--;
        }
        else 
            temp += sacos[i];
    }
    
    return k < c;
}
    
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> c >> t;
    rep(i, 0, n) cin >> sacos[i];
    int l = 0, r = 1e9, res = 1e9;
    while (l + 1 < r){
        int mid = (l + r)/2;
        if (check(mid)){
            r = mid;
            res = min(mid, res);
        }
        else    
            l = mid;
        
    }
    cout << res << '\n';
    return 0;
}
