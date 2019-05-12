#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;

#define MAXN 1000
int peso[MAXN], valor[MAXN], n;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
iii dp[MAXN][MAXN];

iii f(int i, int aguenta){
    if (dp[i][aguenta].first >= 0)    return dp[i][aguenta];
    if (!aguenta || i == n) return dp[i][aguenta] = iii(0, ii(0, 0));
    iii npega = f(i + 1, aguenta);
    if(peso[i] <= aguenta){
        iii pega = f(i + 1, aguenta - peso[i]);
        pega.first += valor[i];
        pega.second.first += peso[i];
        pega.second.second++;
        return pega.first > npega.first ?  dp[i][aguenta] = pega :  dp[i][aguenta] = npega;
        
        
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
        iii res = f(0, 50);
        cout << res.first << " brinquedos\nPeso: " << res.second.first << " kg\nsobra(m) " << (n - res.second.second)<<  " pacote(s)\n\n";
    }
    return 0;
}
