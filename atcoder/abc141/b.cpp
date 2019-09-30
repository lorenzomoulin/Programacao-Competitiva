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
    bool can = true;
    rep(i, 0, sz(s)){
        if (i & 1){
            if (s[i] == 'R')
                can = false;
              
        }
        else{
            if (s[i] == 'L')
                can = false;
        }
    }
    cout << (can ? "Yes\n" : "No\n");
    return 0;
}
