#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define comp(a, b) ((a)*(b))
#define rep(i, a , b) for(int i = a; i < (b); ++i)
using namespace std;

struct Tree {
    typedef pair<int, int> T;
    //const T LOW = ;
    T f(T a, T b) { 
        if (a.first + b.first >= max(a.first, b.first))
            return T(a.first+b.first, a.second+b.second);
        if (a.first == b.first){
            if (a.second > b.second)
                return a;
            return b;
        }
        return (a.first > b.first ? a : b);
            
    } // (any associative fn )
    vector<T> s; int n;
    Tree(int n = 0, T def = T(INT_MIN, 0)) : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos > 1; pos /= 2)
            s[pos / 2] = f(s[pos & ~ 1], s[pos | 1]);
    }
    T query(int b, int e) { // query [ b , e)
        T ra = T(INT_MIN, 0), rb = T(INT_MIN, 0);
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Tree st(n);
        rep(i, 0, n){
            int a;
            cin >> a;
            st.update(i, pair<int, int>(a, 1));
        }
        //for(auto &a: st.s){
        //    cout << a.first << " " << a.second << endl; 
        //}
        int q;
        cin >> q;
        while(q--){
            int a, b;
            cin >> a >> b;
            pair<int, int> res = st.query(a -1, b );
            cout << res.first << " " << res.second << "\n";
        }
    }
    return 0;
}
