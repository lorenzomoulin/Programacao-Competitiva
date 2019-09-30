#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn = 109;
int dp[maxn][maxn];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    memset(dp, 0, sizeof dp);
    rep(i, 1, 101){
        rep(j, 1, 101){
            if (i != j){
                set<int> conj;
                rep(k, 1, i) if (i-k != j) conj.insert(dp[i-k][j]);
                rep(k, 1, j) if (j-k != i) conj.insert(dp[i][j-k]);
                for (int k = 1; i-k > 0 && j-k > 0; k++) conj.insert(dp[i-k][j-k]);
                int mex = 0;
                while(conj.find(mex) != conj.end())
                    mex++;
                dp[i][j] = mex;
            }
        }
    }
    int n, res = 0;
    cin >> n;
    rep(i, 0, n){
        int l, c;
        cin >> l >> c;
        if(l == c){
            cout << "Y\n";
            return 0;
        }
        res ^= dp[l][c];
    }
    cout << (res ? "Y" : "N") << '\n';
    return 0;
}
