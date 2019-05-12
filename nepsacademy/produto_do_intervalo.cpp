#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll neutral = 1;
#define INF 0x3f3f3f3f
#define comp(a, b) ((a)*(b))
#define rep(i, a , b) for(int i = a; i < (b); ++i)
#define left(p) ((p << 1) + 1)
#define right(p) ((p << 1) + 2)


struct Tree {
    typedef char T;
    static const T LOW = '+';
    T f(T a, T b) { 
        if(a == '0' || b == '0')
            return '0';
        if (a != b)
            return '-';
        return '+';
    } // (any associative fn )
    vector<T> s; int n;
    Tree(int n = 0, T def = '+') : s(2*n, def), n(n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos > 1; pos /= 2)
            s[pos / 2] = f(s[pos & ~ 1], s[pos | 1]);
    }
    T query(int b, int e) { // query [ b , e)
        T ra = LOW, rb = LOW;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};


int main(){
    int n, k;
    while(cin >> n >> k){
        Tree st(n);
        int A[n];
        rep(i, 0, n){
            
            int a;
            cin >> a;
            if (a > 0)
                st.update(i, '+');
            else if (a < 0)
                st.update(i, '-');
            else 
                st.update(i, '0');
            
        }
        //st.build(0, 0, n -1, A);
       // for(auto &a: st.s){
       //     cout << a << endl;
       // }
        rep(i, 0, k){
            char c;
            int a, b;
            cin >> c >> a >> b;
            if (c == 'P'){
                char res = st.query(a - 1, b);
                //cout << res << endl;
                cout << res;
            }
            else if (c == 'C'){
                if (b > 0)
                    st.update(a - 1, '+');
                else if (b < 0)
                    st.update(a - 1, '-');
                else 
                    st.update( a - 1, '0');
                
            }
            //for(auto &a: st.a){
           // cout << a << endl;
        //}

        }        
        cout << "\n";
    }
    return 0;
}
