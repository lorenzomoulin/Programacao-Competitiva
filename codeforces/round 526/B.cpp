#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll s;
    cin >> n >> s;
    int v[n];
    ll total = 0;
    for (int i = 0; i < n; i++){ cin >> v[i]; total += v[i];}
    if (total < s){ cout << -1 << endl; return 0;}
    ll soma = 0;
    if (n == 1){    
        cout << v[0] - s << endl;
        return 0;
    }
    stable_sort(v, v + n);
    //cout << "oi\n"<<endl;
    if (v[n - 1] == v[0]){
        ll falta = s - soma;
        //cout << falta << endl;
        ll cont = 0;
        while (falta > (ll)0){
            falta -= (ll)n;
            cont++;
        }
        cout << v[0] - cont << endl;
        
        return 0;
    }
    for (int i = n - 1; i >= 0; i--){
            if (v[i] - v[0] >= s){
                soma += s;
                cout << v[0] << endl;
                return 0;
            }
            if (soma + v[i] - v[0] >= s){
                cout << v[0] << endl;
                return 0;
            }
            //cout << "soma: " << soma << endl;
            
            soma += v[i] - v[0];
            v[i] -= (v[i] - v[0]);
            
    }
    ll inicial = v[0];
    ll falta = s - soma;
    //cout << falta << endl;
    int cont = 0;
    sort(v, v + n);
    while (falta > 0){
        falta -= n;
        cont++;
    }
    cout << v[0] - cont << endl;
    
    return 0;
}
