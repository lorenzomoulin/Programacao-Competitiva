#include <iostream>
#include <cstring>

using namespace std;

const int N_MAX = 25;
const int M_MAX = 1000000;
int m;

int T[N_MAX][M_MAX + 1];

int minimo(int coin[], int n){
    for (int i = 0; i <= m; i++)    T[0][i] = i;
    for (int i = 0; i < n; i++)     T[i][0] = 0;
    for (int i = 1; i < n; i++){
        for (int j = 0; j <= m; j++){
            if (j >= coin[i])   T[i][j] = min(T[i - 1][j], T[i][j - coin[i]] + 1);
            else    T[i][j] = T[i - 1][j];
        }
    }
    return T[n - 1][m];
}

int main(){
    int t;
    cin >> t;   
    while(t--){
        int n;
        cin >> n >> m;
        int coin[n];
        for (int i = 0; i < n; i++) cin >> coin[i];
        int res = minimo(coin, n);
        cout << res << endl;
        
    }       
    return 0;
}
