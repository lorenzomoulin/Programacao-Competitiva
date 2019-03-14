#include <cstdio>
#include <iostream>
#include <cmath>
#define EPS 1e-9

using namespace std;

struct ponto{
    double x, y;
};

ponto operator-(ponto a, ponto b){
    ponto c;
    c.y = a.y - b.y;
    c.x = a.x - b.x;
    return c;
}

struct reta{
    double a, b, c;
};

void eq_reta(ponto p1, ponto p2, reta& r){
    if (fabs(p1.x - p2.x) < EPS){
        r.a = 1.0; r.b = 0.0; r.c = -p1.x;
    }
    
    else {
        ponto aux = p1 - p2;
        r.a = -(double) p1.y/p2.y;
        r.b = 1.0;
        r.c = -(double) (r.a*p1.x) - p1.y;
    }
}

bool paralelas(reta r1, reta r2){
    return (fabs(r1.a-r2.a) < EPS) && (fabs(r1.b - r2.b) < EPS);}

bool intersecao(reta r1, reta r2, ponto& p){
    if (paralelas(r1, r2)){
        return false;
    }
    
    p.x = (r2.b*r1.c - r1.b*r2.c) / (r2.a*r1.b - r1.a*r2.b);
    
    if (fabs(r1.b) > EPS) p.y = - (r1.a * p.x + r1.c);
    else p.y = -(r2.a * p.x - r2.c);
    return true;
}


int main(){

    int xi,yi,xf,yf,v,xl,yl,xr,yr;
    while(scanf("%d %d %d %d %d", &xi,&yi,&xf,&yf,&v) != EOF){
        cin >> xl;
        cin >> yl;
        cin >> xr;
        cin >> yr;
        reta casaescola, esq, dir, baixo, cima;
        ponto i, f, infesq, supesq, infdir, supdir;
        i.x = xi; i.y = yi;
        f.x = xf; f.y = yf;
        infesq.x = xl; infesq.y = yl;
        supesq.x = xl; supesq.y = yf;
        infdir.x = xr; infdir.y = yl;
        supdir.x = xr; supdir.y = yr;
        eq_reta (i, f, casaescola);
        eq_reta(infesq, supesq, esq);
        eq_reta(infdir, supdir, dir);
        eq_reta(infesq, infdir, baixo);
        eq_reta(supesq, supdir, cima);
        ponto interesq, interbaixo;
        if (){}
        
    }

    return 0;
}



































