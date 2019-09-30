#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dp[5009], v[6] = {2, 5, 10, 20, 50, 100}, a[6];

void calc(int s){
    dp[0] = 1;
    rep(i, 1, s + 1){
        int temp[6];
        rep(j, 0, 6)
            temp[j] = a[j];
        
        rep(j, 0, 6){
            if (i >= v[j] && temp[j])
                dp[i] += dp[i - v[j]], temp[j]--;
            
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int s; cin >> s;
    memset(dp, 0, sizeof dp);
    rep(i, 0, 6)
        cin >> a[i];
    calc(s);
    rep(i, 1, s + 1)
        cout << i << ": " << dp[i] << '\n';
    cout << '\n';
    cout << dp[s] << '\n';    
   return 0;
}
