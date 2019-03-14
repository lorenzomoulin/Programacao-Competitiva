#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main (){

    
    int n, h, c, l;
    while (scanf("%d %d %d %d", &n, &h, &c, &l) != EOF){        
        double a = n*sqrt(h*h + c*c)*l;
        printf("%.4lf\n", a/10000);
    }
    return 0;
}
