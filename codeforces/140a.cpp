#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define EPS 1e-4
#define M_PI 3.141592
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int n, r, R;
    cin >> n  >> R>> r;
    
    if (R == r){
        if (n == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
        return 0;
    }
    if (r > R - r){
        if (n*M_PI/2*R*R < M_PI*R*R)
        cout << "YES\n";
    
        else if ( fabs(n*M_PI/2*R*R - M_PI*R*R) < EPS)
            cout << "YES\n";
        else
            cout << "NO\n";
        return 0;
    }
    //cout <<  fabs(n*asin((double)r/(R-r))*R*R - M_PI*R*R) << '\n';
    if (n*asin((double)r/(R-r))*R*R < M_PI*R*R)
        cout << "YES\n";
    
    else if ( fabs(n*asin((double)r/(R-r))*R*R - M_PI*R*R) < EPS)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
