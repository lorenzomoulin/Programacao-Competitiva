#include <iostream>
using namespace std;

int main(){
    long long n, x, cont = 0; cin >> n >> x;
    for (long long i = 1; i <= n; i++){
        if (x % i == 0 && x >= i && x <= i * n) cont ++;
    }
    cout << cont << endl;
    return 0;
}
