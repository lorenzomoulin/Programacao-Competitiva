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
    int n, d, m;
    cin >> n >> d >> m;
    while(m--){
        int x, y;
        cin >> x >> y;
        if (x >= 0 && x <= d){
            if(y >= (-x + d) && y <= (x + d))
                cout << "yes\n";
            else
                cout << "no\n";    
        }
        else if (x >= d && x <= (n - d)){
            if(y >= (x - d) && y <= (x + d))
                cout << "yes\n";
            else
                cout << "no\n";    
        }
        else if (x >= (n - d) && x <= n){
            if(y >= (x - d) && y <= (-x +2*n - d))
                cout << "yes\n";
            else
                cout << "no\n";    
        }
    }
    return 0;
}
