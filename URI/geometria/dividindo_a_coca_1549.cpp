#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

double vt, vc, b, B, H;

double volume (double h){
    double B2 = b + (B - b)*h/(H);
    return M_PI*h*(B2*B2 + B2*b + b*b)/3.0;
}

double solve(double l, double r){
    double h = (l + r)/ 2.0, mid = volume(h);
    
    if (abs(mid - vc) < EPS)    
        return h;
    if (mid > vc)
        solve(l, h);
    else
        solve(h, r);
}

int main(){
    int c;
    cin >> c;
    while(c--){
        double n, l;
        cin >> n >> l >> b >> B >> H;
        vc = l/n;
        double h = solve(0, H);
        printf("%.2f\n", h);
    }
    return 0;
}
