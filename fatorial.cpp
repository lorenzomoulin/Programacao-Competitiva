#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

using namespace std;

typedef unsigned long long ull;

int main(){
    ull stirling, fat = 1;
    for (int i = 1; i <= 20; i++) {
        stirling = sqrt(2*M_PI*i)*pow(i/M_E, i);
        fat *= i;
        cout << "stirling: " << stirling << endl;
        cout << "fat: " << fat << endl;
        
    }
    
    return 0;
}
