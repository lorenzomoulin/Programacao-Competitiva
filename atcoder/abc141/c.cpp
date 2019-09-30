#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 1e5 + 9;
int p[maxn], n, k, q;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> k >> q;
    rep (i,0 , q){
        int a;
        cin >> a;
        p[a]++;
        
    }
    rep(i, 1, n + 1){
        if (k - (q - p[i]) > 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
