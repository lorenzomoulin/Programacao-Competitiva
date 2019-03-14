#include <cmath>
#include <iostream>

using namespace std;

int main(){
    double a,b,c;
    cin >> a >> b >> c;
    if (a == 0) {cout << "Impossivel calcular\n"; return 0;}
    double delta = b*b - 4*a*c;
    if (delta < 0) {cout << "Impossivel calcular\n"; return 0;}
    else{   
        delta = sqrt(delta);    
        double r1 = (-b + delta)/(2*a); 
        double r2 = (-b - delta)/(2*a);
        printf("R1 = %.5lf\nR2 = %.5lf\n", r1, r2);
        //cout << "R1 = " << r1 << endl << "R2 = " << r2 << endl;
    }
    return 0;
}
