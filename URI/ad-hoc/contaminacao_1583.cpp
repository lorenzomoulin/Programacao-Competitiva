#include <bits/stdc++.h>
#define rep(i,a,b ) for(int i = a; i < (b); i++)
using namespace std;
typedef pair<int, int> ii;
int n, m;
char mat[60][60];
bool vis[60][60];

void floodfill(int i, int j){
    if (i < 0 || i >= n || j < 0 || j >= m) return ; // posicao invalida
    if (vis[i][j])  return ; // se ja visitei
    if (mat[i][j] == 'X') { // pedra
        vis[i][j] = true;
        return ;
    }
    
    mat[i][j] = 'T';       // contamina
    vis[i][j] = true;
    floodfill(i + 1, j);   //direita
    floodfill(i, j + 1);   // cima
    floodfill(i - 1, j);   // esquerda
    floodfill(i, j - 1);   // baixo
}

int main(){
    while(true){
        cin >> n >> m;
        if(!n && !m)    break;      //0 0 acaba
        memset(mat, 0, sizeof mat);        //inicializa mapa
        memset(vis, false, sizeof vis);       // nenhum visitado no começo
        vector<ii> t;      //vetor de posicoes que armazena os T's iniciais
        rep(i, 0, n)
            rep(j, 0, m){
                cin >> mat[i][j];
                if (mat[i][j] == 'T')
                    t.push_back(ii(i, j));
            }
        for (auto &a : t)   // para cada posicao que tem T
            floodfill(a.first, a.second);
        rep(i, 0, n){
            rep(j, 0, m)
                cout << mat[i][j]; 
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
