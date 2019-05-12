#include <bits/stdc++.h>
#define endl "\n"

#define rep(i, a ,b) for(int i =a ; i < (b); ++i)
using namespace std;
#define MAXN 1510
typedef long long ll;
ll a[MAXN], dp[MAXN][MAXN];

ll knapsack(int i, int j, bool pontuar){
    if (pontuar){
        if(dp[i][j] >= 0)   return dp[i][j];
        if(i == j)  return dp[i][j] = a[i];
        ll l = a[i] + knapsack(i + 1, j, !pontuar);
        ll r = a[j] + knapsack(i, j - 1, !pontuar);
        return dp[i][j] = max(l, r);
    }
    if(i == j)  return 0;
    ll l = knapsack(i + 1, j, !pontuar);
    ll r = knapsack(i, j - 1, !pontuar);
    return dp[i][j] = max(l, r);
}

int main(){
    int n;
    while(true){
        cin >> n;
        memset(dp, -1, sizeof dp);
        if(!n)
            break;
        rep(i, 0, n){         
            cin >> a[i];       
        }
        
        cout << knapsack(0, n - 1, true) << endl;
    }
    return 0;
}
