#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
#define LL long long
#define ULL unsigned long long
#define LD long double
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(x) ((x)<0?-(x):(x))
#define si(n) scanf("%d",&n)
#define sf(n) scanf("%f",&n)
#define sl(n) scanf("%lld",&n)
#define slu(n) scanf("%llu",&n)
#define sd(n) scanf("%lf",&n)
#define pb push_back
#define ss(n) scanf("%s",n)
#define pnl printf("\n")
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)
#define DB(x) cout<<"\n"<<#x<<" = "<<(x)<<"\n";
#define CL(a,b) memset(a,b,sizeof(a))
#define GOLD ((1+sqrt(5))/2)
const double PI=3.14159265358979323846264338327950288419716939937510582097494459230;
void swaps (char *x,char *y){char temp;temp=*x;*x=*y;*y=temp;}
void swapi(int *a,int *b){int temp;temp=*a;*a=*b;*b=temp;}
#define MAXN 500
int r, c, n;
int visited[MAXN];
typedef pair<int, int> ii;
vector<ii> sequencia;
vector<int> adjList[MAXN];
map<int, ii> mapa;
bool valida(int i, int j){
    return ((i >= 1 && i <= r) && (j >= 1 && j <= c)); 
}

void limpaColuna(int k){
    int i = mapa[k].first, j = mapa[k].second;
    //cout << "i: " << i<< ", j: " << j << "\n";
    for(int l = 1; l < i; l++){
        adjList[k].pb(k - c*(i - l));
    }
    for(int l = i + 1; l <= r; l++){
        adjList[k].pb(k + c*(l - i));
    }
    //cout << "limpaColuna: " << k << "\n";
    //FOR(l, 0, (int)adjList[k].size()){
    //    cout << adjList[k][l].second.first << ", " << adjList[k][l].second.second << " ";
    //}
    //cout << "\n";
    sort(adjList[k].begin(), adjList[k].end());
}

void limpaLinha(int k){
    int i = mapa[k].first, j = mapa[k].second;
    for(int col = 1; col < j; col++){
        adjList[k].pb(k - (j - col));
    }
    for(int col = j + 1; col <= c; col++){
        adjList[k].pb(k + (col - j));
    }
    sort(adjList[k].begin(), adjList[k].end());
}

void limpaDiagPrincipal(int k){
    int i = mapa[k].first, j = mapa[k].second;
    int pos_i = i -1 , pos_j = j - 1, no = k - (c + 1);
    while(valida(pos_i, pos_j)){
        adjList[k].pb(no);
        no -= (c + 1);
        pos_i -= 1;
        pos_j -= 1;
    }
    pos_i = i + 1, pos_j = j + 1, no = k + c + 1;
    while(valida(pos_i, pos_j)){
        adjList[k].pb(no);
        no += (c + 1);
        pos_i += 1;
        pos_j += 1;
    }
    sort(adjList[k].begin(), adjList[k].end());
}

void limpaDiagSecundaria(int k){
    int i = mapa[k].first, j = mapa[k].second;
    int pos_i = i - 1 , pos_j = j + 1, no = k - (c - 1);
    while(valida(pos_i, pos_j)){
        adjList[k].pb(no);
        no -= (c - 1);
        pos_i -= 1;
        pos_j += 1;
    }
    pos_i = i + 1, pos_j = j - 1, no = k + c - 1;
    while(valida(pos_i, pos_j)){
        adjList[k].pb(no);
        no += (c + 1);
        pos_i += 1;
        pos_j -= 1;
    }
    sort(adjList[k].begin(), adjList[k].end());
}

bool movValido(int i1, int j1, int i2, int j2){
    if (i1 == i2)
        return false;
    if (j1 == j2)
        return false;
    if ((i1 + j1) == (i2 + j2))
        return false;
    if ((i2 - j2) == (i1 - j1))
        return false;
    return true;

}

bool deu;

void dfs(int v){
    visited[v] = 1;
    //cout << v << endl;
    /*if (sequencia.size() > 1)
        cout << "(" << sequencia[(int)sequencia.size() -2 ].first << ", " << sequencia[(int)sequencia.size() -2 ].second << ") (" << sequencia[(int)sequencia.size() -1 ].first << ", " << sequencia[(int)sequencia.size() -1 ].second << ")\n";*/
    sequencia.pb(ii(mapa[v]));
    if ((int)sequencia.size() > 1 && !movValido(sequencia[(int)sequencia.size() -2 ].first, sequencia[(int)sequencia.size() -2 ].second,sequencia[(int)sequencia.size() -1 ].first ,sequencia[(int)sequencia.size() -1 ].second )){
        deu = false;
        //cout << "entoru\n";
        //cout << "(" << sequencia[(int)sequencia.size() -2 ].first << ", " << sequencia[(int)sequencia.size() -2 ].second << ") (" << sequencia[(int)sequencia.size() -1 ].first << ", " << sequencia[(int)sequencia.size() -1 ].second << ")\n";
        sequencia.clear();
        return ;
    }
    //cout << 
    for(int j = 1; j <= n; j++){
        if(j == v)
            continue;
        
        if (binary_search(adjList[v].begin(), adjList[v].end(), j))
            continue;
        if(visited[j])
            continue;
        else{
            deu = true;
            dfs(j);
        }
    }
    
    //dfs(i + 1);
    
    return;
}

int main(){
    int t, cases = 1;
    cin >> t;
    while(t--){
        mapa.clear();
        CL(visited, 0);
        sequencia.clear();
        REP(i, MAXN)
            adjList[i].clear();
        cin >> r >> c;
        n = r*c;
        
        int k = 1;
        FOR(i, 1, r + 1){
            FOR(j, 1, c + 1){
                mapa[k] = ii(i, j);
                //cout << "mapa[" << k << "]: (" << mapa[k].first << ", " << mapa[k].second << ")\n";
                k++;
            }
        }
        
        k = 1;
        FOR(i, 1, r + 1){
            FOR(j, 1, c + 1){
            //cout << "mapa[" << k << "]: (" << mapa[k].first << ", " << mapa[k].second << ")\n";
                limpaColuna(k);
                limpaLinha(k);
                limpaDiagPrincipal(k);
                limpaDiagSecundaria(k);
                k++;
            }
        }
        /*FOR(i, 1, n + 1){
            cout << i << endl;
            FOR(j, 0, (int)adjList[i].size()){
                cout << adjList[i][j].first << " ";
            }
            cout << endl;
        }*/
        
        for(int i = 1; i <= n; i++){
            CL(visited, 0);
            sequencia.clear();
            dfs(i);
            if(sequencia.size() == n){
                //cout << i << endl;
                break;
            }
        }
        
        if(sequencia.size() < n){
            cout << "Case #" << cases << ": IMPOSSIBLE\n";
        }
        else{
            cout << "Case #" << cases << ": POSSIBLE\n"; 
            FOR(i, 0, n){
                cout << sequencia[i].first << " " << sequencia[i].second << "\n";
            }
        }
        cases++;
    }
    return 0;
}
