#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 1e9 + 7;
int mat[1009][1009], r[1009], c[1009];

template<typename T>
T modExp(T a, T b, T m) {
    if (b == 0) return (T)1;
    T c = modExp(a, b / 2, m);
    c = (c * c) % m;
    if (b % 2 != 0) c = (c*a) % m;
    return c;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int h, w, cnt = 0;
    cin >> h >> w;
    rep(i, 0, h)cin >> r[i];
    rep(i, 0, w)cin >> c[i];
    rep(i, 0, h){
        rep(j, 0, r[i]){
            if (i == c[j]){
                cout << 0 << '\n';
                return 0;
            }
            mat[i][j] = 1;
        }
    }
     
    rep(j, 0, w){
        rep(i, 0, c[j]){
            if(j == r[i]){
                cout << 0 << '\n';
                return 0;
            }
            mat[i][j] = 1;
        }
    }
    rep(i, 0, h){
        rep(j, 0, w){
           // cout << mat[i][j] << ' ';
            //cout << i << " " << j << ' '<<r[i] << " " << c[j] << '\n';
            if (mat[i][j] == 0 && r[i] != j && c[j] != i)
                cnt++;
        }
            
            //cout << '\n';
    }
    cout << modExp((ll)2, (ll)cnt, (ll)mod) << '\n';
    return 0;
}
