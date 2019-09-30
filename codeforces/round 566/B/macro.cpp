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
    int h, w, res = 0;
    cin >> h >> w;
    char pic[h+1][w+1];
    rep(i, 0, h){
        string s;
        cin >> s;
        rep(j,0, w)
            pic[i][j] = s[j];
    }   
    int j_esq, j_dir, i_cima, i_baixo, i_centro, j_centro;
    rep(i, 0, h){
        bool achou = false;
        int xx = 0;
        rep(j,0, w){
            //printf("%d\n", xx++);
            if (pic[i][j] == '*'){
                int esq = 0, dir = 0, cima = 0, baixo = 0;
                for(int k = j - 1; k >= 0; k--){
                    if (pic[i][k] == '.')
                        break;
                    esq++;
                }
                for(int k = j + 1; k < w; k++){
                    if (pic[i][k] == '.')
                        break;
                    dir++;
                }
                for (int k = i - 1; k >= 0; k--){
                    if (pic[k][j] == '.')
                        break;
                    cima++;
                }
                for (int k = i + 1; k < h; k++){
                    if (pic[k][j] == '.')
                        break;
                    baixo++;
                }
                if (esq && baixo && dir && cima){
                    j_esq = j - esq, j_dir = j + dir, i_baixo = i + baixo, i_cima = i - cima;
                    j_centro = j; i_centro = i;
                    
                    res++;
                    achou = true;
                    break;
                }
            }
        }
        if (achou)
            break;
    }
    //cout << "teste\n";
    if (res == 0){
        cout << "NO\n";
        return 0;
    }
    rep(i, 0, h){
        bool tem = false;
        rep(j, 0, w){
            if (pic[i][j] == '*'){
                if (!((i == i_centro && j >= j_esq && j <= j_dir) || (j == j_centro && i >= i_cima && i <= i_baixo)) ){
                    cout << "NO\n";
                    return 0;
                }
                    
            }
        }
    }
    //cout << res << '\n';
    cout << "YES\n";
    
    return 0;
}
