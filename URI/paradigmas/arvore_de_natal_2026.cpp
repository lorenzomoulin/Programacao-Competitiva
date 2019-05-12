#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b) ; i++)
#define MAXW 1010
#define MAXP 110

using namespace std;

int p, w, peso[MAXP], valor[MAXP], dp[MAXP][MAXW];

int knapsack(int obj, int aguenta){
    if (dp[obj][aguenta] != -1) return dp[obj][aguenta];
       
    if (obj == p)   return dp[obj][aguenta] = 0;
    int nao_pega = knapsack(obj + 1, aguenta);
    if (aguenta - peso[obj] >= 0){
        int pega = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);
        
        return dp[obj][aguenta] = max(pega, nao_pega);
    }
    return dp[obj][aguenta] = nao_pega;
}

int main(){
    int g, caso= 1;
    cin >> g;
    while(g--){
        memset(dp, -1 , sizeof dp);
        
        cin >> p >> w;
        rep(i, 0 ,p){
            cin >> valor[i] >> peso[i];
        }
        cout << "Galho " << caso << ":\nNumero total de enfeites: " << knapsack(0, w) << "\n\n";
        caso++;
    }
    return 0;
}
