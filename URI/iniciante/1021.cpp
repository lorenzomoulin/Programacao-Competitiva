#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int inteira, decimal;
    scanf("%d.%d", &inteira, &decimal);
    int notas[6];int moedas[6];
    int notas2[6] = {100, 50, 20, 10, 5, 2}, moedas2[6] = {100, 50, 25, 10, 5, 1};
    for (int i = 0; i < 6; i++){
        notas[i] = inteira/notas2[i];
        inteira -= notas[i] * notas2[i]; 
    }
    moedas[0] = inteira;
    
    for (int i = 1; i < 6; i++){
        moedas[i] = decimal/moedas2[i];
        decimal -= moedas[i] * moedas2[i];
    }
    cout << "NOTAS:\n";
    
    for (int i = 0; i < 12; i++) {
        if (i == 6){cout << "MOEDAS:\n" << moedas[0] << " moeda(s) de R$ 1.00\n";}
        else if (i > 6 && i < 10){    cout << moedas[i%6] << " moeda(s) de R$ " << "0." << moedas2[i%6] << endl;}
        else if (i >= 10){    cout << moedas[i%6] << " moeda(s) de R$ " << "0." <<"0" << moedas2[i%6]   << endl;}
        else{   cout << notas[i%6] << " nota(s) de R$ " << notas2[i%6] << ".00" << endl ;}
    } 
    return 0;
}
