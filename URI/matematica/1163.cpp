#include <iostream>
#include <cstdio>
#include <cmath>
#include <bits/stdc++.h>
#define G 9.80665
#define PI 3.4159
#define debug(x) cout << #x " = " << (x) << endl
using namespace std;

int main(){
    
    long double h;
    long double pi = 3.14159;
    long double g = 9.80665;
    int p1, p2;
    cout << fixed << setprecision(5);
    while (cin >> h >> p1 >> p2){
        
        int n;
        cin >> n;
        while (n--){
            long double alpha, v;
            cin >> alpha >> v;
            
            if (alpha < 90.0){
                alpha *= pi/180.0;
                long double v2 = v*v;
                long double cos2 = cos(alpha)*cos(alpha);
                
                //double raiz = tan(alpha)*tan(alpha) + ((double)2.0*G*h)/(v2*cos2);
                long double x = (v2*sin(2*alpha)/(2.0*g)) + sqrt(v2*(1.0-cos2) + 2*g*h)*v*cos(alpha)/g;
                 cout << x << " -> ";
                 puts((x >= p1 && x <= p2) ? "DUCK" : "NUCK");
            }
            
        }
    }
    
    

    return 0;
}
