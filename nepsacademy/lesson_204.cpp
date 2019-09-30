#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 1009
int adj[MAXN][MAXN];



int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int m, n;
    cin >> m >> n;
    char mat[m][n];
    rep(i, 0, m){
        rep(j, 0, n){
            cin >> mat[i][j];
        }
    }
    int res = 0;
    rep(i, 0, m){
        rep(j, 0, n){
            if (mat[i][j] == '#'){
                int temp = 0;
                if (i - 1 >= 0){
                    temp += mat[i - 1][j] == '.';
                }
                else
                {
                    temp++;
                }
                
                if (i + 1 < m){
                    temp += mat[i + 1][j] == '.';
                }
                else
                {
                    temp++;
                }
                if (j + 1 < n){
                    temp += mat[i][j + 1] == '.';
                }
                else
                {
                    temp++;
                }
                if (j - 1 >= 0){
                    temp += mat[i][j - 1] == '.';
                }
                else
                {
                    temp++;
                }
                res += temp > 0;
            }
        }
    }
    cout << res << '\n';
    return 0;
}