#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end() 
#define sz(x) (int)(x).size()
#define debug(x) cout << #x " = " << (x) << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXN 100009
#define MOD 9
#define INF 0x3f3f3f3f
const int neutral = 0;
#define comp(a, b) ((a)+(b))
#define left(p) ((p << 1) + 1)
#define right(p) ((p << 1) + 2)

vi st;
int h;
int n;
void build(int *a, int l, int r, int pos){
    //cout << l << " " << r << " " << h << endl;
    if (l == r) {
        st[pos] = a[l];
        //cout << pos << " " << st[pos] << "\n";
        return ;
    }
    if (l > r)
        return ;
    int m = (l + r) / 2;
    int temp = h;
    h++;
    build(a, l, m, 2*pos + 1);
    
    build(a, m + 1, r, 2*pos + 2);
    h--;
    //st[pos] = min(st[2*pos + 1], st[2*pos + 2]);
    //cout << st[pos] << "\n";
    if (h % 2 == 0)
        st[pos] = st[left(pos)] ^ st[right(pos)];
    else    
        st[pos] = st[left(pos)] | st[right(pos)];
    
}



void update(int i, int v){
    st[i += (n - 1)] = v;
    //debug(st[i]);
    i = (i - 1) / 2;
    //h++;
    while (i ){
        
        if (h % 2 == 1){
            st[i] = (st[left(i)] ^ st[right(i)]);
           // cout << "xor\n";
        }
        else {
            st[i] = st[left(i)] | st[right(i)];
            //cout <<"or\n";
        }
        //debug(i);
        //debug(st[i]);
        h++;
        i = (i - 1) / 2;
    }
   // debug(i);
    if (h % 2 == 1){
            //debug(st[left(i)]);
            //debug(st[right(i)]);
            st[i] = (st[left(i)] ^ st[right(i)]);
            //cout << "xor\n";
        }
        else {
            st[i] = st[left(i)] | st[right(i)];
            //cout <<"or\n";
        }  
    //debug(st[i]);
}

int main(){
    int m;
    cin >> n >> m;
    n = 1 << n;
    int a[n];
    
    h = 0;
    st.resize(2*n - 1);
    //cout << sz(st) << endl;
    //Tree st(n);
    rep(i,0, n){
        cin >> a[i];
        //cout << a[i] << '\n';
    }    
    
    build(a, 0, n - 1, 0);
    
    while (m--){
        h = 0;
        int p, b;
        cin >> p >> b;
        update(p - 1, b);
        //for(auto &i: st){
            //cout << i << "\n";
        //}
        cout << st[0] << "\n";
    }
    return 0;
}
