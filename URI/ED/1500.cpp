#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define endl "\n"
const int neutral = 0;
#define comp(a, b) ((a) + (b))

class SegmentTree {
private:
    vector<int> st, lazy;
    int size;
#define left(p) (p << 1)
#define right(p) (left(p) + 1)
    void build(int p, int l, int r, int *A){
        if(l == r) {st[p] = A[l]; return;}
        int m = (l + r )/ 2;
        build(left(p), l, m, A);
        build(right(p), m + 1, r, A);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
    void push(int p, int l, int r){
        st[p] += (r - l + 1)*lazy[p];
        if(l != r){
            lazy[right(p)] += lazy[p];
            lazy[left(p)] += lazy[p];
        }
        lazy[p]=0;
    }
    void update(int p, int l, int r, int a, int b, int k){
        push(p, l, r);
        if(a > r || b < l)  return ;
        if(l >= a && r <= b){
            lazy[p] = k; push(p, l, r); return ;
        }
        int m = (l + r )/ 2;
        update(left(p), l , m, a, b, k);
        update(right(p), m + 1, r, a, b, k);
        st[p] = comp(st[left(p)], st[right(p)]);
    }
    int query(int p, int l, int r, int a, int b){
        push(p, l , r);
        if(a > r || b < l)  return neutral;
        if(l >= a && r <= b){
            return st[p];
        }
        int m = (l + r )/ 2;
        int p1 = query(left(p), l, m, a, b);
        int p2 = query(right(p), m + 1, r, a, b);
        return comp(p1,  p2);
    }
public:
    SegmentTree(int *bg, int *en){
        size = (int)(en - bg);
        st.assign(4*size, neutral);
        lazy.assign(4*size, 0);
        build(1, 0, size -1, bg);
    }
    int query(int a, int b){
        return query(1, 0, size - 1, a, b);
        
    }
    void update(int a, int b, int k){
        update(1, 0, size -1, a, b ,k);
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        int A[n] = {0};
        
        SegmentTree st(A, A + n);
        while(c--){
            int a, b, c, d;
            cin >> a;
            if (a){
                cin >> b >> c;
                cout << st.query(b - 1, c -1) << endl;
            }
            else{
                cin >> b >> c >> d;
                st.update(b - 1, c - 1, d);
            }
        }
    }   
    return 0;
}
