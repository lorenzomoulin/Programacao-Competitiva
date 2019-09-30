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
    int casos = 1;
    while (true){
        int n, q;
        cin >> n >> q;
        if (!n && !q)
            break;
        int a[n];
        rep(i, 0, n)
            cin >> a[i];
        sort(a, a + n);

        cout << "CASE# " << casos << ":\n";
        rep(i , 0 , q){
            
            int b;
            cin >> b;
            if (binary_search(a, a + n, b)){
                cout << b << " found at " << lower_bound(a, a + n, b) - a + 1 << '\n';
            }
            else
                cout << b << " not found\n";
        }
        casos++;
    }
   return 0;
}
