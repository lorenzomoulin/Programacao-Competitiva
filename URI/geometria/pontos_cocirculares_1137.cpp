#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <(b); ++i)
#define sz(x) (int)x.size()
using namespace std;

#define EPS 1e-9

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	bool operator < (point other) const {
		if (fabs(x - other.x) > EPS) return x < other.x;
		else return y < other.y;
	}
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
	point operator +(point other) const {
		return point(x + other.x, y + other.y);
	}
	point operator -(point other) const {
		return point(x - other.x, y - other.y);
	}
	point operator *(double k) const {
		return point(x*k, y*k);
	}
};

double dist(point p1, point p2) {
	return hypot(p1.x - p2.x, p1.y - p2.y);
}

double cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}

bool collinear(point p, point q, point r) {
	return fabs(cross(p-q, r-p)) < EPS;
}

struct circle{
	point c;
	double r;
};

circle circumcircle(point a, point b, point c) {
	circle ans;
	point u = point((b-a).y, -(b-a).x);
	point v = point((c-a).y, -(c-a).x);
	point n = (c-b)*0.5;
	double t = cross(u,n)/cross(v,u);
	ans.c = ((a+c)*0.5) + (v*t);
	ans.r = dist(ans.c, a);
	return ans;
}

int insideCircle(point p, circle c) {
	if (fabs(dist(p , c.c) - c.r)<EPS) return 1;
	
	else return 0;
}

int main(){
    while(true){
        int n, res = 0;
        scanf("%d", &n);
        if(!n)
            break;
        vector<point> vp(n);
        //vector<circle> vc;
        //vector<pair<double, pair<double, double>>> comb;
        rep(i, 0, n){
            double x, y;
            scanf("%lf %lf", &x, &y);
            vp[i] = point(x, y);
        }
        rep(i, 0, n)
            rep(j, i + 1, n)
                rep(k, j + 1, n)
                    if(!collinear(vp[i], vp[j], vp[k])){
                        //vc.push_back(circumcircle(vp[i], vp[j], vp[k]));
                        int temp = 0;
                        circle c = circumcircle(vp[i], vp[j], vp[k]);
                        rep(l, 0, n){
                            if(insideCircle(vp[l], c))
                                temp++;
                        }
                        res = max(res, temp);
                        //comb.push_back(pair<double, pair<double, double>>(i, pair<double, double>(j, k)));
                    }
                    
        
        
        if(res)
            printf("%d\n", res);
        else
            printf("2\n");
    }
    return 0;
}




















