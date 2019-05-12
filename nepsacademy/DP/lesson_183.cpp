#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define MAXN 2010
#define MAXP 2010

ll peso[MAXN], valor[MAXN], n, dp[MAXN][MAXP];

ll knapsack(ll obj, ll aguenta){
    if (dp[obj][aguenta] >= 0)    return dp[obj][aguenta];
    if (!aguenta || obj == n)   return dp[obj][aguenta] = 0;
    
    ll nao_come = knapsack(obj + 1, aguenta);
    
    if (peso[obj] <= aguenta){
        ll come = valor[obj] + knapsack(obj + 1, aguenta - peso[obj]);
        return dp[obj][aguenta] = max(come, nao_come);
    }
    return dp[obj][aguenta] = nao_come;
} 

int main(){
    ll p;
    cin >> p >> n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++)
        cin >> peso[i] >> valor[i];
    cout << knapsack(0, p) << endl; 
    return 0;
}
