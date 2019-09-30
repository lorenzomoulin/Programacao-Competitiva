#include <bits/stdc++.h>
 
using namespace std;
 
#define INF 0x3f3f3f3f
 
int N,M;
 
int cost[1001]; //custo de cada chave
int chave[1001]; // baus que cada chave abre
int memo[1001][5000];
int total; // bits de baus
 
int dp(int key, int baus, int custo){
 
    if (key == N){
        if(baus == total) return custo;
        else return INF;
    }
   
    if(memo[key][baus] != -1) return memo[key][baus];
 
    //usando essa chave
    int a = dp(key+1, baus | chave[key], custo + cost[key]);
   
    //sem usar essa chave
    int b = dp(key+1, baus, custo);
   
    int res = min(a,b);
    memo[key][baus] = res;
   
    return res;
 
}
 
 
int main(){
 
    cin >> N >> M;
    memset(memo, -1, sizeof(memo));
   
    for(int i=0; i<N; i++){
        total |= 1 << i;
    }
   
    for(int i=0; i< M; i++){
        int custo, qtd;
       
        cin >> custo >> qtd;
        cost[i] = custo;
 
        int bau;
        for(int x=0; x<qtd; x++){
            cin >> bau;
            chave[i] |= 1 << (bau - 1);
        }
   
    }
 
    int res = dp(0,0,0);
    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
 
}
