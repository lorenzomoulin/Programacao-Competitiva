#include <iostream>
#include <cmath>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    long double a;
    while (cin >> a){
        long double a1, a2, a3;        
        a1 = a*a*(1.0 + M_PI/3.0 - sqrt(3));
        a2 = M_PI*a*a - 2*a*a - 2*a1; 
        a3 = a*a - a2 - a1;
        printf("%.3Lf %.3Lf %.3Lf\n", a1, a2, a3);
    }
    return 0;
}
