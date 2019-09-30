#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int p,q,r,s,t,u;
int cont  =0 ;
double f(double x){
    
    return p*exp(-x) + q*sin(x) +r*cos(x) + s*tan(x) + t*x*x + u;
}

double solve(double l, double r){
    double mid = (l + r)/2.0;
    double res = f(mid);
    cont++;
    
    if (cont == 10000)
        return -1;
    
    if (abs(res) < EPS)
        return mid;
    if (res > 0)
        return solve(mid, r);
    else
        return solve(l, mid);
}

int main() {
    
    
    while(cin >> p >> q >> r >> s >> t >> u){
        cont = 0;
        double res = solve(0, 1);
        res != -1 ? printf("%.4lf\n", res) : printf("No solution\n") ;            
    } 
    return 0;
}
