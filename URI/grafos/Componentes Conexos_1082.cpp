#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXV 30

vi grafo[MAXV], res;
int v, e, visited[MAXV], numConnected;

void dfs(int u){
    visited[u] = true;
    res.push_back(u);
    trav(a, grafo[u]){
        if (!visited[a])
            dfs(a);
    }
}

void print(){
    sort(all(res));
    trav(a, res){
        cout << (char)('a' + a) << ',';
    }
    cout << '\n';
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int tc, cases = 1;
    cin >> tc;
    while (tc--){
        cout << "Case #" << cases << ":\n";
        rep(i, 0, MAXV) grafo[i].clear();
        memset(visited, 0, sizeof visited);
        numConnected = 0;
        cin >> v >> e;
        rep(i, 0, e){
            char a, b;
            cin >> a >> b;
            grafo[a - 'a'].push_back(b - 'a');
            grafo[b - 'a'].push_back(a - 'a');
        }
        rep(i, 0, v){
            if (!visited[i]){
                res.clear();
                dfs(i);
                numConnected++;
                print();
                
            }
        }
        cout << numConnected << " connected components";
        cout << "\n\n";
        cases++;
    }
   return 0;
}
