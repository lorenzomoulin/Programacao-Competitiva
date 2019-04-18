#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b ) for(int i = a; i < (b);++i)

int main(){
    int c;
    cin >> c;
    while(c--){
        int n;
        cin >> n;
        double media = 0;
        double alunos[n];
        
        rep(i, 0 , n){
            cin >> alunos[i];
            media += alunos[i];
        }
        media /= n;
        int cont = 0;
        rep(i, 0, n){
            if (alunos[i] > media){
                cont++;
            }
        }
        
        printf("%.3f%%\n", (100.0*cont)/n);
    }

    return 0;
}
