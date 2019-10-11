#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6+9;

int n, m;
// para grafos sem peso, bfs calcula menor caminho a todos os vertices
// que s alcança
int bfs(int s, int t){
    vi d(n, INF); d[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        trav(a, g[u]){
            if(d[a] == INF){
                d[a] = d[u] + 1;
                q.push(a);
            }
        }
    }
    return d[t];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    
    return 0;
}
