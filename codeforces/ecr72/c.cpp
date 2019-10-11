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
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 0, n = sz(s);
        rep(i, 1, 19){
            for(int j = 0; j < n - i + 1; ++j){
                int mask = 0;
                for(int k = 0; k < i; k++){
                    if (s[j + k] == '1'){
                        mask |= (1 << (i - k - 1));
                    }
                }
                cout << "mask = " << mask << ", i = " << i<< endl;
                if (mask <= i) ans++;
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}
