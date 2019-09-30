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
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n], b[n];
        rep(i, 0, n)
            cin >> a[i];
        rep (i, 0, n)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        if (a[n-1] + a[n-2] > b[n-2] + b[n-1])
            cout << "AAYUSHI\n";
        else
            cout << "DAKSH\n";
    }
   return 0;
}
