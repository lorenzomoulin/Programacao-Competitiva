#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXN 109
#define MAXW 109
int peso[MAXN], dp[MAXN][MAXW];

int solve(int aluno, int tempo){
    if (dp[aluno][tempo] != -1) return dp[aluno][tempo];
    if (aluno == 0)   return dp[aluno][tempo] = 0;
    
    int pega = 0, npega = solve(aluno - 1, tempo); 
    if (tempo - peso[aluno] >= 0)
        pega = 1 + solve(aluno - 1, tempo - peso[aluno]);
    return dp[aluno][tempo] = max(pega, npega);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, w;
    cin >> n >> w;
    rep(i, 1, n + 1)
        cin >> peso[i];
    //int i = 0;
    cout << "0";
    
    rep(i, 2, n + 1){
        memset(dp, -1, sizeof dp);
        cout <<' '<< i - solve(i - 1, w - peso[i]) - 1;
    }
    cout << '\n';
    return 0;
}
