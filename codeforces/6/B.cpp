#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool valid(int i , int j, int n, int m){
    return !(i < 0 || i >= n || j  < 0 || j >= m);     
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, res = 0;
    char c;
    cin >> n >> m >> c;
    char mat[n][m];
    rep(i, 0, n)rep(j, 0, m)
        cin >> mat[i][j];
    bool inicio = true;
    pii origem, fim;
    rep(i, 0, n){
        rep(j, 0, m){
            if (c == mat[i][j]){
                origem.first = i, origem.second = j;
                //cout << origem.first << ", " << origem.second << '\n';
                inicio = false;
                break;
            }    
        }
        if (!inicio)
            break;
    }
    inicio = true;
    for (int i = n - 1; i >= 0; i--){
        for (int j = m - 1; j >= 0; j--){
            if (c == mat[i][j]){
                fim.first = i, fim.second = j;
                inicio = false;
                break;
            }
        }
        if (!inicio)
                break;
    }
    //cout << origem.first << ", " << origem.second << '\n' << fim.first << ", " << fim.second << '\n';
    int memo[256];
    memset(memo, 0, sizeof memo);
    //borda superior
    if (origem.first > 0){
        rep(j, origem.second, fim.second + 1){
            //cout << mat[origem.first - 1][j];
            if (mat[origem.first - 1][j] != '.')
                res += !memo[mat[origem.first - 1][j]], memo[mat[origem.first - 1][j]]++;
        }
    }
    //cout << '\n' << res << '\n';
    if (origem.second > 0){
        rep(i, origem.first, fim.first + 1){
            //cout << mat[i][origem.second - 1];
             if (mat[i][origem.second - 1] != '.')
                res += !memo[mat[i][origem.second - 1]], memo[mat[i][origem.second - 1]]++;               
        }
    }
    //cout << '\n' << res << '\n';
    if (fim.first < n - 1){
        rep(j, origem.second, fim.second + 1){
            //cout << mat[fim.first + 1][j];
            if (mat[fim.first + 1][j] != '.')
                res += !memo[mat[fim.first + 1][j]], memo[mat[fim.first + 1][j]]++;
        }
    }
    //cout << '\n' << res << '\n';
    if (fim.second < m - 1){
        rep(i, origem.first, fim.first + 1){
            //cout << mat[i][fim.second + 1];
             if (mat[i][fim.second + 1] != '.')
                res += !memo[mat[i][fim.second + 1]], memo[mat[i][fim.second + 1]]++;               
        }
    }
    cout << res << '\n';
    
    return 0;
}
