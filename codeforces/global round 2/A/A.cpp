#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n;
    cin >> n;
    int c[n];
    rep(i, 0 , n){
        cin >> c[i];
        
    }
    
    int i = 0, j = n-1, maior = 0, tam = n - 1;
    rep(k, 0, n - 1){
        while(c[i] == c[j] && tam > maior){
            j--;
            tam--;
        }
        if(tam > maior)
            maior = tam;
        
        rep(g, i, n-1){
            if(c[g] != c[i]){
                i = g;
                break;
            }
        }
        j = n -1, tam = j - i;
        if(tam <= maior)
            break;
    }
    
    if (tam > maior) maior = tam;
    cout << maior << endl;
}
