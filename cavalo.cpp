#include <iostream>
#include <vector>
using namespace std;    
#define pb(i) push_back(i) 


struct ponto{
    int x, y;
};

typedef vector<ponto> vp;

vp possiveis_casas(ponto p){
    vp x;
    if (p.x + 1 <= 7 && p.y - 2 >= 0){
        ponto n;
        n.x  = p.x + 1; n.y = p.y - 2;
        x.pb(n);
    }
    if (p.x + 1 <= 7 && p.y + 2 <= 7){
        ponto n;
        n.x  = p.x + 1; n.y = p.y + 2;
        x.pb(n);
    }
    if (p.x - 1 >= 0 && p.y - 2 >= 0){
        ponto n;
        n.x  = p.x - 1; n.y = p.y - 2;
        x.pb(n);
    }
    if (p.x - 1 >= 0 && p.y + 2 <= 7){
        ponto n;
        n.x  = p.x - 1; n.y = p.y + 2;
        x.pb(n);
    }
    if (p.x + 2 <= 7 && p.y - 1 >= 0){
        ponto n;
        n.x  = p.x + 2; n.y = p.y - 1;
        x.pb(n);
    }
    if (p.x + 2 <= 7 && p.y + 1  <= 7){
        ponto n;
        n.x  = p.x + 2; n.y = p.y + 1;
        x.pb(n);
    }
    if (p.x - 2 >= 0 && p.y - 1 >= 0){
        ponto n;
        n.x  = p.x - 2; n.y = p.y - 1;
        x.pb(n);
    }
    if (p.x - 2 >= 0 && p.y + 1 <= 7){
        ponto n;
        n.x  = p.x - 2; n.y = p.y + 1;
        x.pb(n);
    }
    return x;
}

int main(){
    ponto p;
    p.x = 0; p.y = 0;
    vp x = possiveis_casas(p);
    for (int i = 0; i < x.size(); i++)  cout << x[i].x << " " << x[i]. y << endl;
    return 0;
}
