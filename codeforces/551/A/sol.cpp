#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define INF 0x3f3f3f3f
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, t;
    cin >> n >> t;
    pii bus[n + 1];
    
    int menor = INF, menor_i;
    rep(i, 1, n + 1){
        int a,b ;
        
        cin >> a >> b;
        while (a < t)
            a += b;
        if (a < menor)
            menor = a, menor_i = i;
        
    }
    //cout << menor_i << endl;
    /*if (menor == INF){
        rep(i, 1, n + 1){
       
            int time = (int)ceil((t - bus[i].first)/(float)bus[i].second)*bus[i].second + bus[i].first;
             //cout << time << endl;
            if (time  >= t && time < menor)
                menor_i = i, menor = time;
        }
        cout << menor_i << endl;
    }*/
    
    //else {
        cout << menor_i << endl;
    //}
    return 0;
}
