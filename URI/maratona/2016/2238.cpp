#include <iostream>

using namespace std;

int main(){
    int a, b, c, d, n, k1 = 1;
    
    cin >> a >> b >> c >> d;
    if (c < a){cout << -1 << endl;  return 0;}
    while(true){
        n = a*k1++;
        if ((n % a == 0) && (n % b != 0) && (c % n == 0) && (d % n != 0)){cout << n << endl; return 0;} 
    }
    return 0;
}
