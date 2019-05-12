#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9

struct point {
	double x, y;
	point() { x = y = 0.0; }
	point(double _x, double _y) : x(_x), y(_y) {}
	double norm() { return hypot(x, y); }
	point normalized() {
		return point(x,y)*(1.0/norm());
	}
	double angle() { return atan2(y, x); }
	double polarAngle() {
		double a = atan2(y, x);
		return a < 0 ? a + 2*acos(-1.0) : a;
	}
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
double inner(point p1, point p2) {
	return p1.x*p2.x + p1.y*p2.y;
}
double cross(point p1, point p2) {
	return p1.x*p2.y - p1.y*p2.x;
}
bool ccw(point p, point q, point r) {
	return cross(q-p, r-p) > 0;
}
bool collinear(point p, point q, point r) {
	return fabs(cross(p-q, r-p)) < EPS;
}
point rotate(point p, double rad) {
	return point(p.x * cos(rad) - p.y * sin(rad),
	p.x * sin(rad) + p.y * cos(rad));
}
double angle(point a, point o, point b) {
	return acos(inner(a-o, b-o) / (dist(o,a)*dist(o,b)));
}
point proj(point u, point v) {
	return v*(inner(u,v)/inner(v,v));
}
bool between(point p, point q, point r) {
	return collinear(p, q, r) && inner(p - q, r - q) <= 0;
}
point lineIntersectSeg(point p, point q, point A, point B) {
	double c = cross(A-B, p-q);
	double a = cross(A, B);
	double b = cross(p, q);
	return ((p-q)*(a/c)) - ((A-B)*(b/c));
}
bool parallel(point a, point b) {
	return fabs(cross(a, b)) < EPS;
}
bool segIntersects(point a, point b, point p, point q) {
	if (parallel(a-b, p-q)) {
		return between(a, p, b) || between(a, q, b)
			|| between(p, a, q) || between(p, b, q); 
	}
	point i = lineIntersectSeg(a, b, p, q);
	return between(a, i, b) && between(p, i, q);
}
point closestToLineSegment(point p, point a, point b) {
	double u = inner(p-a, b-a) / inner(b-a, b-a);
	if (u < 0.0) return a;
	if (u > 1.0) return b;
	return a + ((b-a)*u);
}

struct circle{
	point c;
	double r;
	circle() { c = point(); r = 0; }
	circle(point _c, double _r) : c(_c), r(_r) {}
	double area() { return acos(-1.0)*r*r; }
	double chord(double rad) { return  2*r*sin(rad/2.0); }
	double sector(double rad) { return 0.5*rad*area()/acos(-1.0); }
	bool intersects(circle other) {
		return dist(c, other.c) < r + other.r;
	}
	bool contains(point p) { return dist(c, p) <= r + EPS; }
	pair<point, point> getTangentPoint(point p) {
		double d1 = dist(p, c), theta = asin(r/d1);
		point p1 = rotate(c-p,-theta);
		point p2 = rotate(c-p,theta);
		p1 = p1*(sqrt(d1*d1-r*r)/d1)+p;
		p2 = p2*(sqrt(d1*d1-r*r)/d1)+p;
		return make_pair(p1,p2);
	}
	vector< pair<point,point> > getTangentSegs(circle other) {
		vector<pair<point, point> > ans;
		double d = dist(other.c, c);
		double dr = abs(r - other.r), sr = r + other.r;
		if (dr >= d) return ans;
		double u = acos(dr / d);
		point dc1 = ((other.c - c).normalized())*r;
		point dc2 = ((other.c - c).normalized())*other.r;
		ans.push_back(make_pair(c + rotate(dc1, u), other.c + rotate(dc2, u)));
		ans.push_back(make_pair(c + rotate(dc1, -u), other.c + rotate(dc2, -u)));
		if (sr >= d) return ans;
		double v = acos(sr / d);
		dc2 = ((c - other.c).normalized()) * other.r;
		ans.push_back({c + rotate(dc1, v), other.c + rotate(dc2, v)});
		ans.push_back({c + rotate(dc1, -v), other.c + rotate(dc2, -v)});
		return ans;
	}
	pair<point, point> getIntersectionPoints(circle other){
		assert(intersects(other));
		double d = dist(c, other.c);
		double u = acos((other.r*other.r + d*d - r*r) / (2*other.r*d));
		point dc = ((other.c - c).normalized()) * r;
		return make_pair(c + rotate(dc, u), c + rotate(dc, -u));
	}
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
	else if (dist(p , c.c) < c.r) return 0;
	else return 2;
} //0 = inside/1 = border/2 = outside

circle incircle( point p1, point p2, point p3 ) {
    double m1=dist(p2, p3);
    double m2=dist(p1, p3);
    double m3=dist(p1, p2);
    point c = (p1*m1+p2*m2+p3*m3)*(1/(m1+m2+m3));
    double s = 0.5*(m1+m2+m3);
    double r = sqrt(s*(s-m1)*(s-m2)*(s-m3))/s;
    return circle(c, r);
}

circle minimumCircle(vector<point> p) {
	random_shuffle(p.begin(), p.end());
	circle C = circle(p[0], 0.0);
	for(int i = 0; i < (int)p.size(); i++) {
		if (C.contains(p[i])) continue;
		C = circle(p[i], 0.0);
		for(int j = 0; j < i; j++) {
			if (C.contains(p[j])) continue;
			C = circle((p[j] + p[i])*0.5, 0.5*dist(p[j], p[i]));
			for(int k = 0; k < j; k++) {
				if (C.contains(p[k])) continue;
				C = circumcircle(p[j], p[i], p[k]);
			}
		}
	}
	return C;
}

typedef vector<point> polygon;

double signedArea(polygon & P) {
	double result = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		result += cross(P[i], P[(i+1)%n]);
	}
	return result / 2.0;
}

int leftmostIndex(vector<point> & P) {
	int ans = 0;
	for(int i=1; i<(int)P.size(); i++) {
		if (P[i] < P[ans]) ans = i;
	}
	return ans;
}

polygon make_polygon(vector<point> P) {
	if (signedArea(P) < 0.0) reverse(P.begin(), P.end());
	int li = leftmostIndex(P);
	rotate(P.begin(), P.begin()+li, P.end());
	return P;
}

double perimeter(polygon & P) {
	double result = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) result += dist(P[i], P[(i+1)%n]);
	return result;
}

double area(polygon & P) {
	return fabs(signedArea(P));
}

bool isConvex(polygon & P) {
	int n = (int)P.size();
	if (n < 3) return false;
	bool left = ccw(P[0], P[1], P[2]);
	for (int i = 1; i < n; i++) {
		if (ccw(P[i], P[(i+1)%n], P[(i+2)%n]) != left)
			return false;
	}
	return true;
}

bool inPolygon(polygon & P, point p) {
	if (P.size() == 0u) return false;
	double sum = 0.0;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		if (P[i] == p || between(P[i], p, P[(i+1)%n])) return true;
		if (ccw(p, P[i], P[(i+1)%n])) sum += angle(P[i], p, P[(i+1)%n]);
		else sum -= angle(P[i], p, P[(i+1)%n]);
	}
	return fabs(fabs(sum) - 2*acos(-1.0)) < EPS;
}

polygon cutPolygon(polygon & P, point a, point b) {
	vector<point> R;
	double left1, left2;
	int n = P.size();
	for (int i = 0; i < n; i++) {
		left1 = cross(b-a, P[i]-a);
		left2 = cross(b-a, P[(i+1)%n]-a);
		if (left1 > -EPS) R.push_back(P[i]);
		if (left1 * left2 < -EPS) 
			R.push_back(lineIntersectSeg(P[i], P[(i+1)%n], a, b));
	}
	return make_polygon(R);
}

int main(){
    int n, h, l;
    cin >> n >> l >> h;
    polygon p;
    for(int i = 0; i < n;++i){
        int x, y;
        cin >> x >> y;
        p.push_back(point(x, y));
    }
    circle c = minimumCircle(p);
    cout << perimeter(p) << " " << c.area() << endl;
    return 0;
}
