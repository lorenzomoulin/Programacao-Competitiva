#include <bits/stdc++.h>
#define MAXN 110
#define MAXP 10000
#define rep(i,a ,b ) for(int i = a; i < (b); i++)
using namespace std;

int n, peso[MAXN], valor[MAXN], dp[MAXN][MAXP];

int knapsack(int obj, int aguenta){
    if (dp[obj][aguenta] != -1)    return dp[obj][aguenta];
    if (obj == n)   return dp[obj][aguenta] = 0;
    
    int nao = knapsack(obj + 1, aguenta);
    
    if (aguenta - peso[obj] >= 0){
        int sim = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);
        return dp[obj][aguenta] = max(nao, sim);
    }
    return dp[obj][aguenta] = nao;
}

int main(){
    while(true){
        cin >> n;
        if (!n ) break;
        memset(dp, -1, sizeof dp);
        rep(i, 0, n){
            cin >> valor[i] >> peso[i];
        }
        int p;
        cin >> p;
        cout << knapsack(0, p) << '\n';
    }
    return 0;
}
