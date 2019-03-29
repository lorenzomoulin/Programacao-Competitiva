#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < n; i++)

using namespace std;

typedef pair<int, int> ii;

int T[101][601];
vector<ii> atracoes;

void compute(int n, int t){

	FOR(i, t + 1){
		T[0][i] = atracoes[0].second*(i / atracoes[0].first);
    }
	for (int i = 0; i < n; i++)     T[i][0] = 0;
	
	FOR(i, n){
		FOR(j, t + 1){
			if (j < atracoes[i + 1].first)
				T[i + 1][j] = T[i][j];
			else 
				T[i + 1][j] = max(T[i][j], 
				T[i + 1][j - atracoes[i + 1].first] + atracoes[i + 1].second);

		}

	}

}


int main(){
	ios_base::sync_with_stdio(0);
	int instancia = 1;
	while(true){
		int n, t;
		atracoes.clear();
		cin >> n >> t;
		if (!n && !t)
			break;
		
		FOR(i, n){
			int d, p;
			cin >> d >> p;
			atracoes.push_back(ii(d, p)); 
		}
		sort(atracoes.begin(), atracoes.end());
		compute(n, t);
		cout << "Instancia " << instancia << endl;
		cout << T[n - 1][t] << endl << endl;
		instancia++;
	}
	return 0;
}
