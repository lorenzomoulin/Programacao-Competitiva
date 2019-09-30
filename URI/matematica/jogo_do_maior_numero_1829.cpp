#include <bits/stdc++.h>

using namespace std;

int main(){
    int n ;
    cin >> n;
    int v[n];
    int cont1 = 0, cont2 = 0;
    for (int i = 0; i < n; i++){
        int a, b, n;
        char circ, exc;
        cin >> a >> circ >> b >> n >> exc;
        if (b*log(a) > (0.5*log(2*M_PI) + (n + 0.5)*log(n) - n)){
            v[i] = 1, cont1++;
        }
        else
            v[i] = 2, cont2++;
    }
    
    if (cont1 == cont2)
        cout << "A competicao terminou empatada!\n";
    else if (cont1 > cont2)
        cout << "Campeao: Lucas!\n";
    else
        cout << "Campeao: Pedro!\n";
    for (int i = 0; i < n; i++){
        if (v[i] == 1)
            cout << "Rodada #" << i + 1 << ": Lucas foi o vencedor\n";
        else
            cout << "Rodada #" << i + 1 << ": Pedro foi o vencedor\n";
    }
    return 0;
}
