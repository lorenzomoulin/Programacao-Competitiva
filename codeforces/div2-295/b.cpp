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
const int MAXN = 2e5;

int n, m;
vi adj[MAXN + 9];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n >> m;
    rep(i, 1, 10001){
        adj[i].push_back(2*i);
        adj[i].push_back(i-1);
    }
    int s = n;
    vi d(MAXN, INF); d[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        trav(a, adj[u]){
            int v = a;
            if (d[v] == INF){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    cout << d[m] << '\n';
    return 0;
}
