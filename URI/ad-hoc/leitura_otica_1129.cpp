#include <bits/stdc++.h>

using namespace std;

//1 é preto
//0 é branco

int main(){
    while(true){
        int n;
        cin >> n;
        if (!n)
            break;
        while (n--){
            int op[5], menor = 128, qtd = 0;
            char menori = '*';
            bool sem = true;
            for (int i = 0; i < 5; i++){
                cin >> op[i];
                if (op[i] <= 127){
                    menor = op[i], menori = 'A' + i, qtd++;
                }
                    
                
            }
            
            
                if (qtd == 1)
                    cout << menori << '\n';
                else 
                    cout << "*\n";
            
            
        }
    }
    return 0;
}
