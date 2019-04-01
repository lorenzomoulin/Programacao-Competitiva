#include <bits/stdc++.h>
#define MAXN 200009
#define pb push_back
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<int> adjList[MAXN];
vii edges;
vector<bool> visited(MAXN);
vector<int> color(MAXN);

bool isBipartite(int v) 
{ 
  
    for (int u : adjList[v]) { 

        if (visited[u] == false) { 
  
            visited[u] = true; 

            color[u] = !color[v]; 

            if (!isBipartite(u)) 
                return false; 
        } 
        else if (color[u] == color[v]) 
            return false; 
    } 
    return true; 
} 


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    FOR(i, m){
        int u, v;
        scanf("%d%d", &u, &v);
        adjList[u].pb(v);
        adjList[v].pb(u);
        edges.pb(ii(u, v));
    }
    
    visited[1] = true;
    color[1] = 0;
    
    if(isBipartite(1)){
        printf("YES\n");
        FOR(i, m){
            printf("%d", !color[edges[i].first]);
        }
        printf("\n");
    }
    else
        printf("NO\n");
    
    return 0;
}
