#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 1005
#define UNVISITED -1
int num[MAXN], low[MAXN], parent[MAXN],component[MAXN], counter, rootChildren, articulationVertex[MAXN], root, vis[MAXN], numSCC;
stack<int> S;
vi bi[MAXN], uni[MAXN];
int n, m;
bitset<MAXN> visited;
int cont;

bool dfs1(int v){
    visited[v] = 1;
    rep(i, 0, sz(uni[v])){
        if(!visited[uni[v][i]]){
            dfs1(uni[v][i]); cont++;
        }
    }
    return cont == n;
}
bool dfs2(int v){
    visited[v] = 1;
    rep(i, 0, sz(bi[v])){
        if(!visited[bi[v][i]]){
            dfs2(bi[v][i]); cont++;
        }
    }
    return cont == n;
}

bool bridge;

void tarjan(int u){
    low[u] = num[u] = counter++;
    for(int j= 0, v; j < sz(uni[u]); j++){
        v = uni[u][j];
        if(num[v] == UNVISITED){
            parent[v] = u;
            if(u == root)   rootChildren++;
            tarjan(v);
            if(low[v] >= num[u])    articulationVertex[u] = true;
            if(low[v] > num[u]){ 
                int conta = 0;
                for(int i = 0; i < sz(uni[u]); i++)
                    if(uni[u][i] == v){
                        conta++;
                        break;      
                    }
                for(int i = 0; i < sz(uni[v]); i++)
                    if(uni[v][i] == u){
                        conta++;
                        break;      
                    }
                if(conta == 1)
                    bridge = true;
            }                
            low[u] = min(low[u], low[v]);
        }
        else if(v != parent[u]) low[u] = min(low[u], num[v]);
    }
    
}


int main(){
    cin.sync_with_stdio(0);
    while(cin >> n >> m){
        counter = numSCC = 0;
        memset(vis, 0 , sizeof vis);
        memset(num, UNVISITED, sizeof num);
        memset(low, 0, sizeof low);
        memset(parent, 0, sizeof parent);
        memset(articulationVertex, 0, sizeof articulationVertex);
        rep(i, 0, MAXN)
            bi[i].clear(), uni[i].clear();
        visited.reset();
        rep(i, 0, m){
            int u, v , dir;
            cin >> u >> v >> dir;
            if(!i)
                continue;
            u--, v--;
            uni[u].pb(v);
            if(dir == 2){
                uni[v].pb(u); 
            }
            bi[u].pb(v), bi[v].pb(u);
        }
        
        bool flag = true;
        rep(i, 0, n){
            visited.reset();
            cont = 1;

            if(!dfs1(i)){
                
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "-\n";
            continue;
        
        }

        visited.reset();
        cont = 1;
        flag = true;
        rep(i, 0, n){
            if(!dfs2(0)){
                cout << "*\n";
                flag = false;
                break;
            }
        }
        if(!flag)
            continue;
        bridge = false;
        for (int i = 0; i < n; i++)
		    if (num[i] == UNVISITED) {
			    root = i; rootChildren = 0; tarjan(i);
			    articulationVertex[root] = (rootChildren > 1);
		    }
        if(bridge)
            cout << "2\n";
        else
            cout << "1\n";
    }
    return 0;
}
