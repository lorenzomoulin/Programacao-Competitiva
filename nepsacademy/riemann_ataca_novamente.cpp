#include <bits/stdc++.h>

using namespace std;

bitset<1300010> e_composto;
int primos[1300010];
int primo, cont;

void crivo(int n){
      cont = 0;
      e_composto[1] = 1; // 1 não é composto, mas o vetor na verdade guarda os números que não são primos
      for(int i = 2; i <= n; ++i){
        if(!e_composto[i]){
          for(int j = 2; j*i <= n; ++j){
            e_composto[i*j] = 1;
          }
          cont++;
          primos[i] = cont;
        }
          }
      return;
}

int main(){
    
    //cin >> x;
    int q;
    cin >> q;
    //idx =0 ;
    crivo(1300000);
    
    while(q--){
        int c;
        cin >> c;
        cout << primos[c] << "\n";
    }
    //cout << primo;
    
    //cout << "\n";
    return 0;
}
