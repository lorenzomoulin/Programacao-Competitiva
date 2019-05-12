#include <bits/stdc++.h>
#define D define
#define  rep(i, a, b) for(int i = a; i <(b); ++i )
using namespace std;
#define MAXN 1010

int n, m, dp[MAXN][MAXN], s1[MAXN], s2[MAXN];

int lcs(int a , int b){
    if (dp[a][b] >= 0)  return dp[a][b];
    if (!a || !b)   return dp[a][b] = 0;
    if (s1[a] == s2[b])     return dp[a][b] = 1 + lcs(a - 1, b - 1);
    return dp[a][b] = max(lcs(a-1, b), lcs(a, b- 1));
}

int main(){
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    rep(i, 1 , n + 1){
        cin >> s1[i];
    }
    rep(i, 1, m + 1){
        cin >> s2[i];
    }
    cout << (n - lcs(n, m)) << " " << (m - lcs(n, m)) << '\n';
    return 0;
}
