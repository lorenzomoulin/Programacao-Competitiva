#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    int x = (n - 1)/ 2, soma = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        //soma += a[i]*(2*(abs(x - i) + abs(i) + abs(x)));
    }
    int res = 999999999;
    for (int i = 0; i < n; i++){
        soma = 0;
        for (int j = 0; j < n; j++){
            soma += a[j]*(2*(abs(i - j) + abs(j) + abs(i)));
        }
        //cout << soma << endl;
        res = min(res, soma);
    }
    cout << res << endl;
    return 0;
}
