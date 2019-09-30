#include <bits/stdc++.h>
#define EPS 1e-5
using namespace std;

int n, a, c[100010];

double solve(double l, double r){
    
    double mid = (l + r) / 2.0, b = 0;
    for (int i = 0; i < n; i++){
        b += (c[i] > mid) ? c[i] - mid : 0;
    }
    if (abs(b - a) < EPS)
        return mid;
    
    (b > a) ? solve(mid, r) : solve(l, mid);
}

int main(){
    while (true){
        
        scanf("%d%d", &n, &a);
        if (!n and !a)
            break;
        int maior = 0, sum = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &c[i]), maior = max(maior, c[i]), sum += c[i];
        
        
        if (sum < a){
            printf("-.-\n");
            continue;
        }
        double res = solve(0, maior);
        if (abs(res) < EPS){
            printf(":D\n");
        }
        
        else{
            printf("%.4lf\n", res);
        }
        
    }
    return 0;
}
