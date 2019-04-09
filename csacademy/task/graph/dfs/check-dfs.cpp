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
#define MAXN 100005
#define UNVISITED -1
int n, m, rec;
vi l[MAXN];
int visited[MAXN], permutation[MAXN], i, parent[MAXN], counter, last;

bool dfs(int u){
    visited[u]++;
    
    
    
    if(u != 1)
        parent[u] = last;
    
    cout << "i: " << i << " permutation " << permutation[i] <<  endl;
    cout << "visited : " << u << endl; //<< "counter: " << counter << endl;
    cout << "parent " << u << ": " << parent[u] << endl;
    
    vi::iterator p = find(all(l[u]), permutation[i + 1]);
    //cout <<( p != l[u].end() )<< endl;
    if(p != l[u].end()){
        //cout << "entrouz\n";
        i++;
        counter++;
        last = u;
        dfs(permutation[i]);
        
    }
    else {
        last = u;
        //cout << "oi\n";
        if(u == 1)
            return false;
        dfs(parent[u]);
    }
    
    
    
    if(counter == n)
        return true;
    else
        return false;   
}

int main(){
    ios_base::sync_with_stdio(0);    
    
    
    cin >> n >>m;
    memset(visited, UNVISITED, sizeof visited);
    memset(parent, -1, sizeof parent);
    rep(j, 0, n){
        cin >> permutation[j];
    }
    i = 0;
    counter = 1;
    last = 1;
    parent[1] = -1;
    while(m--){
        int u, v;
        cin >> u >> v;
        l[u].pb(v);
        l[v].pb(u);          
    }
    dfs(1) ? cout << "1\n" : cout << "0\n"; 
    
    return 0;
}
