#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define pb push_back
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct point{
    double x, y;
    point() {x = y = 0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
    point operator -(point other) const{
        return point(x - other.x, y - other.y);
    }
};
double cross(point p1, point p2){
    return p1.x*p2.y - p1.y*p2.x;
}
struct triangle{
    point a, b, c;
    triangle() { a = b = c = point();}
    triangle(point _a, point _b, point _c) : a(_a), b(_b), c(_c) {}
    int isInside(point p){
        double u = cross(b-a,p-a)*cross(b-a,c-a);
        double v = cross(c-b,p-b)*cross(c-b,a-b);
        double w = cross(a-c,p-c)*cross(a-c,b-c);
        if(u > 0.0 && v > 0.0 && w > 0.0)
            return 0;
        if (u < 0.0 || v < 0.0 || w < 0.0)
            return 2;
        else return 1;
    }
};



int isInsideTriangle(triangle t, point p){
    return t.isInside(p);
}



int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, xa, xb;
    cin >> n >> xa >> xb;
    point a = point(xa, 0);
    point b = point(xb, 0);
    point t[n];
    rep(i, 0, n){
        int x, y;
        cin >> x >> y;
        t[i] = point(x, y);    
        //cout << angulos[i].first << ", " << angulos[i].second << "\n";     
    }
    int res = 0;
    rep(i, 0, n){
        int temp = 1;
        rep(j, 0, i){
            if (isInsideTriangle(triangle(a, b, t[i]), t[j]) != 2 )
                temp++;
        }
        rep(j, i + 1, n){
            if (isInsideTriangle(triangle(a, b, t[i]), t[j]) != 2)
                temp++;
        }
        res = max(res, temp);
    }
    cout << res << "\n";
    return 0;
}
