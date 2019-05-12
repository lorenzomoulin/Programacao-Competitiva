#include <bits/stdc++.h>
#define rep(i, a, b) for(int i= a; i < (b); ++i)
#define INF 0x3f3f3f3f
#define endl "\n"
#define MAXN 100000009

using namespace std;
typedef pair<int, int> ii;
int rs[MAXN], ls[MAXN], st[MAXN], cnt = 0;

class SegmentTree2D{
    int sizex, sizey, v, root;
    int x, y, ix, jx, iy, jy;
    void updatex(int p, int lx, int rx){
        if(x < lx || rx < x)    return ;
        st[p] += v;
        if(lx == rx)    return ;
        if(!rs[p]) rs[p] = ++cnt, ls[p] = ++cnt;
        int mx = (lx + rx) / 2;
        updatex(ls[p], lx, mx);
        updatex(rs[p], mx + 1, rx);
    }
    void updatey(int p, int ly, int ry){
        if(y < ly || ry < y)    return ;
        if(!st[p])  st[p] = ++cnt;
        updatex(st[p], 0, sizex);
        if(ly == ry)    return ;
        if(!rs[p]) rs[p] = ++cnt, ls[p] = ++cnt;
        int my = (ly + ry) / 2;
        updatey(ls[p], ly, my);
        updatey(rs[p], my + 1, ry);
    }
    int queryx(int p, int lx, int rx){
        if(!p || jx < lx || ix > rx)    return 0;
        if(ix <= lx && rx <= jx)    return st[p];
        int mx = (lx + rx) / 2;
        return queryx(ls[p], lx, mx) + queryx(rs[p], mx + 1, rx);
    }
    int queryy(int p, int ly, int ry){
        if(!p || jy < ly || iy > ry) return 0;
        if(iy <= ly && ry <= jy)    return queryx(st[p], 0, sizex);
        int my = (ly + ry) / 2;
        return queryy(ls[p], ly, my) + queryy(rs[p], my + 1, ry);
    }
public:
    SegmentTree2D(int nx, int ny) : sizex(2*nx), sizey(2*ny){
        root = ++cnt;
    }
    void update(int _x, int _y, int _v){
        x = _x, y = _y, v = _v;
        updatey(root, 0, sizey);
    }
    int query(int _ix, int _jx, int _iy, int _jy){
        ix = _ix, jx = _jx, iy = _iy, jy = _jy;
        return queryy(root, 0, sizey);
    }
};

int main(){
    int n;
    cin >> n;
    SegmentTree2D s(n, n);
    rep(i, 0, n){
        rep(j, 0, n){
            int v;
            cin >> v;
            s.update(i, j, v);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        cout << s.query(i1 ,j1, i2, j2) << endl;
    }
    
    
    
    
    return 0;
}
