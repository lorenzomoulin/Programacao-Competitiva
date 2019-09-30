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
    int k, n;
    cin >> k;
    string erradas;
    cin >> erradas;
    cin >> n;
    int res = 0;
    char respostas[n][k];
    rep(i, 0, n){
        rep(j, 0, k){
            cin >> respostas[i][j];
        }
    }
    int table[26];
    rep(j, 0, k){
        memset(table, 0, sizeof table);
        rep(i, 0, n){
            if (respostas[i][j] != erradas[j])
                table[respostas[i][j] - 'A']++;
        }
        res += *max_element(table, table + 26);
    }
    
    cout << res << '\n';
    return 0;
}
