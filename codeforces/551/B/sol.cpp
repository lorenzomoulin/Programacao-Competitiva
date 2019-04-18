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
    int n, m, h;
    cin >> n >> m >> h;
    int res[n + 1][m + 1], front[m + 1], left[n + 1], top[n + 1][m + 1];
    rep(i, 1, m + 1){
        cin >> front[i];
    }
    rep(i, 1, n + 1){
        cin >> left[i];    
    }
    rep (i, 1, n +1){
        rep(j, 1, m+1){
            cin >> top[i][j];
        }
    }
    rep(j, 1, m + 1){
        for(int i = n; i >= 0; i--){
            if (top[i][j] && left[i] >= front[j])
                top[i][j] = front[j];
        }
    }
    rep(i, 1, n + 1){
        for(int j = m; j >= 0; j--){
            if(top[i][j] && front[j] >= left[i])
                top[i][j] = left[i];
        }
    }
    
    rep(i, 1, n + 1){
        cout << top[i][1];
        rep(j, 2, m + 1){
            cout << " " << top[i][j];
        }
        cout << "\n";
    }
    return 0;
}
