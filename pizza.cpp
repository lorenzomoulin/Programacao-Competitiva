#include <iostream>
#include <cmath>
#include <cstdio>
#define EPS 1e-9

using namespace std;

struct ponto {
    double x, y;
    
};

ponto delta(ponto a, ponto b){
    ponto c;
    c.x = a.x-b.x;
    c.y = a.y-b.y;    
}

struct reta {
    double a, b, c;
};

void _2pontos1reta(ponto p1, ponto p2, reta &r){
    if (fabs(p1.x - p2.x) < EPS) {
        r.a = 1.0; r.b = 0.0; r.c = -p1.x;
    }
    
    else {
        r.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
        r.b = 1.0;
        r.c = -(double) (r.a*p1.x) - p1.y;
    }
    
}

bool paralelas(reta r1, reta r2){
    return (fabs(r1.a-r2.a) < EPS) && (fabs(r1.b-r2.b) < EPS) ;}
    
bool intersecao(reta r1, reta r2, ponto &p){
    if (paralelas(r1, r2))  return false;
    p.x = (r2.b*r1.c - r1.b*r2.c) / (r2.a*r1.b - r1.a*r2.b);
    if (fabs(r1.b) > EPS)   p.y = -(r1.a*p.x + r1.c);
    else                    p.y = -(r2.a*p.x + r2.c);
    
    return true;

}

int main (){

    int x,y,h,v, n;
    cin >> x;
    cin >> y;
    cin >> h;
    cin >> v;
    n = h + v;
    reta r[n];
    int i = 0;
    while (h--){
        double y1, y2;
        cin >> y1;
        cin >> y2;
        ponto a, b;
        a.x = 0.0;
        a.y = y1;
        b.x = x;
        b.y = y2;
        
        _2pontos1reta(a, b, r[i]);
        i++;
    }
    while (v--){
        double x1, x2;
        cin >> x1;
        cin >> x2;
        ponto a, b;
        a.y = 0.0;
        a.x = x1;
        b.y = y;
        b.x = x2;
        
        _2pontos1reta(a, b, r[i]);
        i++;
    }
    int soma = 0;
    for (int k = 0; k < n-1; k++){
        for (int j = k+1; j < n; j++){
            ponto p;
            bool inter = intersecao(r[k], r[j], p);
            if (inter && (p.x > 0.0 && p.x < x) && (p.y > 0.0 && p.y < y)){
                soma++;
            }
        }
    }
    printf("%d\n", soma + n + 1);
    return 0;
}
