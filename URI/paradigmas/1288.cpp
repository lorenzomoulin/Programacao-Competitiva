#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;

#define MAXN 1000
int peso[MAXN], valor[MAXN], dp[MAXN][MAXN], n;

int f(int i, int aguenta){
    if (dp[i][aguenta] >= 0)    return dp[i][aguenta];
    if (!aguenta || i == n) return dp[i][aguenta] = 0;
    int npega = f(i + 1, aguenta);
    if(peso[i] <= aguenta){
        int pega = valor[i] + f(i + 1, aguenta - peso[i]);
        return dp[i][aguenta] = max(pega, npega);
    }
    return dp[i][aguenta] = npega;
}

int main(){
    int t;
    cin >> t;
    while(t-- ){
        memset(dp, -1, sizeof dp);
        cin >> n;
        rep(i, 0, n){
            cin >> valor[i] >> peso[i];
        }
        int k, res; cin >> k;
        cin >> res;
        int miss = f(0, k);
        cout << (miss >= res ? "Missao completada com sucesso\n" : "Falha na missao\n") ;
    }
    return 0;
}
