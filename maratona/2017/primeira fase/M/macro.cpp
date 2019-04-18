#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int a[3];
    cin >> a[0] >> a[1] >> a[2] ;
    int custo1 = 0, custo2 = 0, custo3 = 0;
    int maior_i = 0;
    rep(i, 0, 3){
        custo1 += 2*abs(i - maior_i)*a[i];
    }
    maior_i = 1;
    rep(i, 0, 3){
        custo2 += 2*abs(i - maior_i)*a[i];
    }
    
    maior_i = 2;
    rep(i, 0, 3){
        custo3 += 2*abs(i - maior_i)*a[i];
    }
    cout << min(custo1, min(custo2, custo3)) << "\n";
   return 0;
}
