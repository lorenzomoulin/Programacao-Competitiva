#include <vector>
#include <queue>
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f
#define MAXN 1009
using namespace std;

/*
 * Hopcroft-Karp's Algorithm O(E*sqrt(V))
 */

vector<int> adjU[MAXN];
int pairU[MAXN], pairV[MAXN], dist[MAXN];
int m, n;
//Vertices enumerados de 1 a m em U e de 1 a n em V!!!!

bool bfs() {
    queue<int> q;
    for (int u = 1; u <= m; u++) {
        if (pairU[u] == 0) {
            dist[u] = 0; q.push(u);
        }
        else dist[u] = INF;
    }
    dist[0] = INF;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] >= dist[0]) continue;
        for (int i = 0; i < (int)adjU[u].size(); i++) {
            int v = adjU[u][i];
            if (dist[pairV[v]] == INF) {
                dist[pairV[v]] = dist[u] + 1;
                q.push(pairV[v]);
            }
        }
    }
    return (dist[0] != INF);
}

bool dfs(int u) {
    if (u == 0) return true;
    for (int i = 0; i < (int)adjU[u].size(); i++) {
        int v = adjU[u][i];
        if (dist[pairV[v]] == dist[u]+1) {
            if (dfs(pairV[v])) {
                pairV[v] = u; pairU[u] = v;
                return true;
            }
        }
    }
    dist[u] = INF;
    return false;
}

int hopcroftKarp() {
    memset(&pairU, 0, sizeof pairU);
    memset(&pairV, 0, sizeof pairV);
    int result = 0;
    while (bfs()) {
        for (int u=1; u<=m; u++) {
            if (pairU[u]==0 && dfs(u))
                result++;
        }
    }
    return result;
}
int main(int argc, char const *argv[])
{
	int t, caso = 0;
	cin >> t;
	while (t--){
		
		for (int i = 0; i < MAXN; ++i)
		{
			adjU[i].clear();
		}
		cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		cin >> m;
		int b[m];
		for (int i = 0; i < m; ++i)
		{
			cin >> b[i];
		}
		for (int i = 0; i < n; i++){
	        for (int j = 0; j < m; j++){

	            if (b[j] != 0 && a[i] == 0)
	              	continue;

	            if (b[j] == 0){
	            	adjU[i + 1].push_back(j + n + 1);
	            	adjU[j + n + 1].push_back(i + 1);
	            	
	               
	            }

	            else if( b[j] % a[i] == 0){
	                adjU[i + 1].push_back(j + n + 1);
	            	adjU[j + n + 1].push_back(i + 1);
	            }
	        }
	    }
	   
	    
	    caso++;
	    cout << "Caso #" << caso << ": " << hopcroftKarp() << endl;
	}
	return 0;
}
