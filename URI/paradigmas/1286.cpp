#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;

#define MAXN 40
int peso[MAXN], valor[MAXN], dp[MAXN][MAXN];
int n;
int f(int i, int aguenta){
    if (dp[i][aguenta] >= 0)    return dp[i][aguenta];
    if (!aguenta || i == n) return 0;
    int nao_pega = f(i + 1, aguenta);
    if(peso[i] <= aguenta){
        int pega = valor[i] + f(i + 1, aguenta - peso[i]);
        return dp[i][aguenta] = max(pega, nao_pega);
    }
    return dp[i][aguenta] = nao_pega;
}

int main(){
    
    while(true){
        
        
        cin >> n;
        if(!n)  break;
        memset(dp, -1, sizeof dp);
        int p;
        cin >> p;
        rep(i, 0, n){
            cin >> valor[i] >> peso[i];
        }
        cout << f(0, p) << " min.\n";
    }
    return 0;
}
