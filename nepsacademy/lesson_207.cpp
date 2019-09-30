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


int adj[MAXN][MAXN], grau[MAXN];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int caso = 1;
    while (true){
        memset(adj, 0, sizeof adj);
        memset(grau, 0, sizeof grau);
        int a, v;
        cin >> a >> v;
        if (!a && !v)   break;
        rep(i, 0, v){
            int x, y;
            cin >> x >> y;
            adj[x][y] = 1;
            grau[x]++;
            grau[y]++;
        }
        int maior = 0;
        rep(i, 1, a + 1){
            maior = max(maior, grau[i]);
        }
        
        int qtd = 0;
        cout << "Teste " << caso << '\n';
        caso++;
        rep(i, 1, a + 1){
            if (grau[i] == maior)
                cout << i << ' ';
        }
        cout << '\n' << '\n';
    }
   return 0;
}
