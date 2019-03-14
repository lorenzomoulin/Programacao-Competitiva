#include <iostream>
#include <algorithm>

using namespace std;

int l;
int k;
int m;
int n;
int x[100000];

int guloso(){
    int qtd_h = 0, qtd_v = 0;
    bool completo = false;
    if ((m * 100) % l == 0){
        for (int i = 1; i <= (m*100)/l; i++){
            for(int j = k - 1; j >= 0; j--){
                
            }
        }
    }
    
    return qtd;
}

int main (){
    while (true){      
        cin >> m >> n;
        if (!(m || n))  break;
        cin >> l >> k;
        if ((m*100)%l && (n*100)%l) {
            cout << "impossivel" << endl;
            break;
        }
        for (int i = 0; i < k; i++) cin >> x[i];
        stable_sort(x, x + k);
            
    }
    return 0;
}
