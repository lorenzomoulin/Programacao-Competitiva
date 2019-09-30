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
    int n, q;
    cin >> n;
    int a[n];
    rep(i, 0, n)
        cin >> a[i];
    cin >> q;
    while (q--){
        int b;
        cin >> b;
        int l = lower_bound(a, a + n, b) - a, r = upper_bound(a, a + n, b) - a;
        //cout << l << " " << r << '\n'; 
        if (l  == 0)
            cout << "X ";
        else
            cout << a[l - 1] << " ";
        if (r == n)
            cout << "X";
        else
            cout << a[r];
        cout << '\n';
    }
   return 0;
}
