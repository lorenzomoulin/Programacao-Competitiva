#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAXN = 1e5+9;
vi g[MAXN];
int n, sub[MAXN];
bool flag = true;

void dfs(int s){
    sub[s] = 1;
    trav(a, g[s]){    
        dfs(a);
        sub[s] += sub[a];        
    } 
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        g[b].push_back(a);
    }
    dfs(0);
    rep(i, 0, n + 1){
        int a = sz(g[i]) ? sub[g[i][0]]: 0;
        rep(j, 1, sz(g[i])){
            if (a != sub[g[i][j]]){
                flag = false;
                cout << "mal\n";
                return 0;
            }
        }
    }    
    cout << "bem\n";
    return 0;
}
