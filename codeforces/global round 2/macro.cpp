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
    int i = 0, j = 1, maior = 0, tam = 0;
    while(j < n){
        if(c[i] != c[j]){
            j++;
            tam++;
        }
        else {
            i++;
            if(tam > maior)
                maior = tam;
             tam--;
            
        }
    }
    cout << tam << endl;
}
