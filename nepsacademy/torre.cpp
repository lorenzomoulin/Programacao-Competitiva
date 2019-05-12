#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define ms(a, x) memset(a, x, sizeof a) 
using namespace std;

int main(){
    int n;
    cin >> n;
    int t[n][n];
    rep(i, 0, n){
        rep(j, 0 , n){
            cin >> t[i][j];
        }
    }
    int peso_linha[n], peso_coluna[n];
    ms(peso_linha, 0);
    ms(peso_coluna, 0);
    rep(i, 0, n)
        rep(j, 0 , n)
            peso_linha[i] += t[i][j], peso_coluna[j] += t[i][j];

    int peso =0 ;
    rep(i, 0, n)
        rep(j, 0, n)
            peso = max(peso, peso_linha[i] + peso_coluna[j] - 2*t[i][j]);
    cout << peso << endl;
    return 0;
}
