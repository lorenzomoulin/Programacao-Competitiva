#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 100009
set<int> adj[MAXN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, m;
    cin >> n >> m;
    while (m--){
        int t, a, b;
        cin >> t >> a >> b;
        if (t){
            adj[a].insert(b);
            adj[b].insert(a);
        }
        else
        {
            set<int>::iterator it = adj[a].find(b);
            if (it != adj[a].end())
                cout << "1\n";
            else
            {
                cout << "0\n";
            }
            
        }
        
    }
   return 0;
}
