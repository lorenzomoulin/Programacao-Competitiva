#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define INF 1000000
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int h, l, mat[210][210], vis[210][210], small = INF, smallcolor, temp;

void maior(int i, int j, int color){
    if (i < 0 || i >= h || j < 0 || j >= l) return ;
    if (vis[i][j])  return ;
    if (mat[i][j] != color) return ;
    vis[i][j] = 1;
    temp++;
    maior(i + 1, j, color);
    maior(i, j + 1, color);
    maior(i - 1, j, color);
    maior(i, j - 1, color);
}



int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> h >> l;
    memset(vis, 0, sizeof vis);
    rep(i, 0, h)
        rep(j, 0, l)
            cin >> mat[i][j];
    rep(i, 0, h){
        rep(j, 0, l){
            temp = 0;
            maior(i, j, mat[i][j]);
            //cout << temp << '\n';
            if (temp < small && temp)
                small = temp, smallcolor = mat[i][j];
        }
    }
    cout << small << '\n';
    return 0;
}
