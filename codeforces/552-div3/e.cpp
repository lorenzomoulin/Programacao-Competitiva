#include <bits/extc++.h>
using namespace __gnu_pbds;
using namespace std;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, 
            tree_order_statistics_node_update>;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 2e5+9;
int n, k, team[MAXN], b[MAXN], g, idx, j, cnt;
pii a[MAXN];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    g = 1;
    cin >> n >> k;
    rep(i, 0, n) cin >> a[i].first, a[i].second = i, b[i] = a[i].first;
    sort(a, a + n);
    idx = a[n-1].second;
    j = n - 1;
    Tree<int> t;
    rep(i, 0, n) t.insert(i);
    while(sz(t)){
        int ord = t.order_of_key(idx), l, r;
        l = min(k, ord), r = min(sz(t) - ord - 1, k);
        team[idx] = g;
        vi err; err.push_back(idx);
        for(int i = 1; i <= l; i++){
            int key = *t.find_by_order(ord-i); 
            if (team[key] == 0){
                team[key] = g;
                err.push_back(key);
            }
        }
        for(int i = 1; i <= r; i++){
            int key = *t.find_by_order(ord+i); 
            if (team[key] == 0){
                team[key] = g;
                err.push_back(key);
            }
        }
        trav(x, err){
            t.erase(x);
        }
        for(; j >=0 && team[a[j].second] != 0; j--);
        if (j < 0) break;
        idx = a[j].second;
        
        g = 3 - g;
    }
    rep(i, 0, n) cout << team[i];
    cout << '\n';
    return 0;
}
