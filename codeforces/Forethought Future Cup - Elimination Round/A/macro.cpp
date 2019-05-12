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
    string s;
    cin >> s;
    int a = 0;
    trav(b, s)
        if(b == 'a')
            a++;
    if(a > sz(s)/ 2){
        cout << sz(s) << "\n";
        return 0;
    }
    
    cout << ((a - 1) * 2 + 1) << "\n";
    
    return 0;
}
