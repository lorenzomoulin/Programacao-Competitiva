#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1e5+9;
int a[maxn], n;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    ll cost = 0;
    bool zero = false;
    rep(i, 0, n){
        cin >> a[i];
        if (!a[i])
            zero = true;
        if (a[i] < 0){
            cost += -1 - a[i];
            a[i] += -1 - a[i];
            
        }
        else{
            cost += abs(a[i] - 1);
            a[i] -= a[i] - 1;
        }
    }
    int p = 1;
    rep(i, 0, n){
        p*=a[i];
        //cout << a[i] << ' ';
        
    }
    cout << '\n';
    if (p < 0 && !zero)
        cost += 2;
    cout << cost << '\n';
    return 0;
}
