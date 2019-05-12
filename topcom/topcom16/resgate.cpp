#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) (int)x.size()
#define isnum(c) (c >= '0' && c <= '9')
#define endl "\n"
using namespace std;

#define MAXN 2000
#define INF 0x3f3f3f3f

typedef pair<int, int> ii;
//int adjList[MAXN][MAXN], prox[MAXN][MAXN];
vector<ii> adjList[MAXN];
int dist[MAXN], n, m, parent[MAXN];


int dijkstra(int s, int t) {
	for(int i = 1; i <= n; i++) dist[i] = INF;
	set<ii> pq;
	dist[s] = 0;
	pq.insert(ii(0, s));
	while(!pq.empty()) {
		int u = pq.begin()->second;
		pq.erase(pq.begin());
		for(int i=0; i<(int)adjList[u].size(); i++) {
			int v = adjList[u][i].second;
			int w = adjList[u][i].first;
			if (dist[v] > dist[u] + w) {
			    if(dist[v] < INF)
				    pq.erase(ii(dist[v], v));
				dist[v] = dist[u] + w;
				parent[v] = u;
				pq.insert(ii(dist[v], v));
			}
		}
	}
	return dist[t];
}

/*
void floydwarshall(){
    rep(k, 1, n + 1){
        rep(i, 1, n + 1){
            rep(j, 1, n + 1){
                if(adjList[i][j] > adjList[i][k] + adjList[k][j]){
                    adjList[i][j] = min(adjList[i][j], adjList[i][k] + adjList[k][j]), prox[i][j] = prox[i][k];
                }
                
                }
        }
    }
}
*/

void caminho(int source, int target, deque<int> &path){
    
    int u = target;
    if(parent[u] != -1 || parent[u] == source){
        while (u != -1){
            path.push_front(u);
            u = parent[u];
        }    
    }  
}

int main(){
    while(true){
        rep(i, 0, MAXN){
            adjList[i].clear();
        }
        memset(parent, -1, sizeof parent);
            //memset(adjList[i], 0, sizeof adjList[i]);
        
        int p, r;
        cin >> p >> r;
        if(!p && !r)
            break;
        int nvit;
        cin >> nvit;
        int vit[nvit];
        rep(i, 0, nvit)
            cin >> vit[i];
        n = p*p - r;

        cin >> m;
        rep(i, 0, m){
            int u, v, w;
            cin >> u >> v >> w;
            adjList[u].push_back(ii(w, v));
           // prox[u][v] = v;
        }

        
        cout << "Caminhos e esforco do robo do ponto de apoio ate as vitimas:\n";
        rep(i, 0, nvit){
            if(vit[i] <= n){
                memset(parent, -1, sizeof parent);
                int c = dijkstra(1, vit[i]);
                //cout << "esforco = " << c << endl;
                cout << "Vitima " << i + 1<< ":\n";
                deque<int> path;
                caminho(1, vit[i], path);
                for(auto &a: path){
                    cout << a << " ";
                }
                
                cout << "esforco = " << c << endl;
            }
        }
    }
    return 0;
}
