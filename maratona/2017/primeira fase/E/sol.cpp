#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define MOD 12

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;



int padrao[7] = {2, 2, 1, 2, 2, 2, 1};
string notas[12] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
int escalas[12][8];

void gera(){
    rep(i, 0, 12){
        escalas[i][0] = i + 1;
        rep(j, 1, 8){
            escalas[i][j] = ((escalas[i][j -1] + padrao[j-1] - 1) % MOD) + 1;
        }
    }
    /*rep(i, 0, 12){
        rep(j, 0, 8){
            cout << escalas[i][j] << " ";
        }
        cout << "\n";
    }*/
}



int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    gera();
    int n;
    cin >> n;
    set<int> s;
    while(n--){
        int a;
        cin >> a;
        if (a > 12)
            s.insert(a % MOD);
        else
        
            s.insert(a);        
    }
   
    rep(i, 0, 12){
        bool tem = true;
        trav(a, s){
            bool esta = false;
            rep(j, 0, 8){
                if (escalas[i][j] == a){
                    esta = true;
                }
            }
            if (!esta){
                tem = false;
                break;
            }
                
        }
        if (tem){
            cout << notas[i] << "\n";
            return 0;
        }
        
    }
    cout << "desafinado\n";
    
    return 0;
}
