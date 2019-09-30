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
    int p, c, n, total;
    cin >> p >> c >> n;
    total = p + c;
    bool folha = false;
    int cont = 0;
    int folhas[n];
    rep(i, 0, n){
        cin >> folhas[i];
    }
    rep (i, -1, n - 1){
        if (i < 0 && total > folhas[i + 1]){
            c -= (total - folhas[i + 1]);
            total = p + c;
        }
        else if (i >= 0 && total > folhas[i + 1] && c >= (total - folhas[i + 1])){
            c -= total - folhas[i + 1];
            total = p + c;
            cont++;
        }
    }
    cout << cont << '\n';
    return 0;
}
