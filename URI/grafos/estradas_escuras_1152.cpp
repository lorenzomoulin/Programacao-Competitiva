#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int , int> ii;

int N, M;
vector< pair<ll, ii> > edgeList; // (weight, two vertices) of the edge

class UnionFind {
private:
	vector<int> parent, rank;
public:
	UnionFind(int N) {
    	rank.assign(N+1, 0);
		parent.assign(N+1, 0);
		for (int i = 0; i <= N; i++) parent[i] = i;
	}
	int find(int i) {
		while(i != parent[i]) i = parent[i];
		return i;
	}
	bool isSameSet(int i, int j) {
		return find(i) == find(j);
	}
	void unionSet (int i, int j) {
		if (isSameSet(i, j)) return;
		int x = find(i), y = find(j);
		if (rank[x] > rank[y]) parent[y] = x;
		else {
			parent[x] = y;
			if (rank[x] == rank[y]) rank[y]++;
		}
	}
};

ll kruskal() {
	ll cost = 0;
	UnionFind UF(N);
	pair<ll, ii> edge;
	sort(edgeList.begin(), edgeList.end());
	for (int i = 0; i < M; i++) {
		edge = edgeList[i];
		if (!UF.isSameSet(edge.second.first, edge.second.second)) { 
			cost += edge.first;
			UF.unionSet(edge.second.first, edge.second.second);
		}
	}
	return cost;
}




int main(){
    
    while(true){
        edgeList.clear();
        cin >> N >> M;
        if (!N && !M) break;
        ll res = 0;
        for(int i = 0; i < M; i++){
            int x, y, z;
            cin >> x >> y >> z;
            edgeList.push_back(pair<ll, ii>(z, ii(x, y)));
            res += z;
            
        }
        cout << (res - kruskal()) << '\n';
        
    }
    
    return 0;
}

























