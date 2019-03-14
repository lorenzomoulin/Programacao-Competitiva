#include <iostream>

using namespace std;
#define f(n, i) for(i = 0; i < n; i++)

int T[8][100005];
int fat[8] = {1, 2, 6, 24, 120, 720, 5040, 40320};

int k(int n){
    int i, j;
    f(n+1, i)    T[0][i] = i;
    f(8, j)      T[j][0] = 0;
    for(i = 1; i < 8; i++){
        f(n+1, j){
            if (j >= fat[i]){
                T[i][j] = min(T[i - 1][j], T[i][j - fat[i]] + 1);
            }
            else{
                T[i][j] = T[i - 1][j];
            }
        }
    }
    /*
    for (i = 1; i < 8; i++){
        f(n+1, j){
            cout << T[i][j] << " ";
            
        }
        cout << endl;
    }*/
    return T[7][n];
}


int main(){
    
    int n; cin >> n;
    
    cout << k(n) << endl;
}
