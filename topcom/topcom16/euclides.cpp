#include <bits/stdc++.h>

using namespace std;
#define endl "\n"
#define debug(x) cout << #x << " = " << x << endl
#define EPS 1e-9

struct point{
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
    
    point operator -(point other) const{
        return point(x - other.x, y - other.y);
    }
};



double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double inner(point p1, point p2){
    return p1.x*p2.x + p1.y*p2.y;
}

double angle(point a, point o, point b){
    return acos(inner(a-o, b-o)/ (dist(o, a)*dist(o, b)));
}
struct triangle{
    point a, b, c;
    triangle(point _a, point _b, point _c) : a(_a), b(_b), c(_c){}
    double perimeter() { return dist(a, b) + dist(b, c) + dist(c, a);}
    double semiperimeter() { return perimeter()/2.0;}
    
    double area(){
        double s = semiperimeter(), ab = dist(a, b), bc = dist(b,c ), ca = dist(c, a);
        return sqrt(s*(s - ab)*(s - bc)*(s - ca));
    }
};
int main(){
    double xa, ya, xb, yb, xc, yc, xd, yd, xe, ye, xf, yf;
    while(true){
        cin >> xa >> ya >> xb >>yb >> xc >> yc >> xd >> yd >> xe >> ye >> xf >> yf;
        if (!(xa || ya || xb || yb || xc || yc || xd || yd || xe || ye || xf || yf))
            break;
        point a = point(xa,  ya), b = point(xb, yb), c = point(xc, yc);
        triangle def = triangle(point(xd, yd), point(xe, ye), point(xf, yf));
        double s1 = def.area();
        double ab = dist(a, b);
        double ac = dist(a, c);
        double cab = angle(c, a, b);
        double ah = s1 / (sin(angle(c, a, b))* ab);
        //debug(ah);
        ///debug(ac);
        //debug (ab);
        double yh = ya + (yc - ya)*ah/ac;
        double xh = xa + (xc - xa)*ah/ac;
        double xg = xb + ah*cos(cab);
        double yg;
        double dx = xb - xa;
        double dy = yb - ya;
        xg = xh + dx, yg = yh + dy;
            //yg = yb + s1/ab;
        printf("%.3f %.3f %.3f %.3f\n", xg, yg, xh, yh); 
    }
    return 0;
}
