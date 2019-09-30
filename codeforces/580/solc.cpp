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
    
    int n;
    cin >> n;
    int a[2*n + 9];
    if (n % 2 == 0){
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int cur = 1;
    bool sum3 = true;
    cout << cur;
    rep(i,1 , n){
        cur += (sum3 ? 3 : 1);
        cout << ' ' << cur;
        sum3 = !sum3;
    }
    cur = 2;
    cout << ' ' << cur;
    sum3 = false;
    rep(i, 1, n){
        cur += (sum3 ? 3 : 1);
        cout << ' ' << cur;
        sum3 = !sum3;
    }
    cout << '\n';
    return 0;
}
