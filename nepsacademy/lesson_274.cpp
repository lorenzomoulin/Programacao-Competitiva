#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n, q;
    cin >> n;
    vi fila(n);
    rep(i, 0, n)
        cin >> fila[i];
    cin >> q;
    while (q--){
        ll t, i, x;
        cin >> t >> i >> x;
        if (t){
            int j;
            for (j = i - 2; j >= 0; j--){
                if (fila[j] > fila[i - 1] + x){
                    cout << j + 1<< '\n';
                    break;
                }
            }
            if (j < 0)
                cout << "0\n";
            
        }
        else {
            n++;
            vi esq, dir;
            rep(j, 0, i)
                esq.push_back(fila[j]);
            rep(j, i, n)
                dir.push_back(fila[j]);
            esq.push_back(x);
            esq.insert(esq.end(), all(dir));
            
            fila = esq;
        }
    }
    return 0;
}
