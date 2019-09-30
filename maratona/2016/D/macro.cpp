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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    set<int> div;
    for (ll i = 1; i*i <= c; i++)
        if (c % i == 0)
            div.insert(i), div.insert(c/i);
    trav(i, div){
        if (i % a == 0 && i % b != 0 && c % i  == 0 && d % i != 0){
        
            cout << i << '\n';
            return 0;
        }
    } 
    cout << "-1\n";
    return 0;
}
