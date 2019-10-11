#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MAXN = 3e5;
const int INF = 1e9;
int n, m;
//vi adj[MAXN];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int t;
    
    cin >> t;
    while (t--){
        //rep(i, 0, MAXN) adj[i].clear();
        
        cin >> n >> m;
        vi adj[n+9];
        rep(i, 0, m){
            int a, b;
            cin >> a >> b;
            a-- ,b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vi clr(n, INF); clr[0] = 0;
        queue<int> q; q.push(0);
        int ans = INF, c1 = 1, c2 = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            trav(v, adj[u]){
                if (clr[v] == INF){
                    clr[v] = 1 - clr[u];
                    clr[v] == 1? c2++ : c1++;
                    q.push(v);
                }
            }
        }
        if (c1 < c2){
            cout << c1 << '\n';
            rep(i, 0, n){
                if (clr[i] == 0)
                    cout << i+1 << ' ';
            }
            cout << '\n';
        }
        else{
            cout << c2 << '\n';
            rep(i, 0, n){
                if (clr[i] == 1)
                    cout << i+1 << ' ';
                
            }
            cout << '\n';
        }
    }   
    return 0;
}
