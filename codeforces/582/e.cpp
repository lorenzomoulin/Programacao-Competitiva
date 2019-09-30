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
    string pos[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
    string ini = "aaa";
    /*vector<string> pos;
    pos.push_back(ini);
    while (next_permutation(all(ini))){
        pos.push_back(ini);
    }*/
    int n;
    string s,t, test;
    cin >> n >> s >> t;
       
    
    rep(a, 0, 6){
        rep(b, 0, 6){
            bool can = true;
            test = "";
            test = pos[a] + pos[b] + pos[a];
            //cout << test << '\n';
            rep(i, 0, 8){
                
                if (test.substr(i, 2) == s || test.substr(i, 2) == t){
                    can = false;
                    break;
                }
            }
            if (can){
                cout << "YES\n";
                test = "";
                bool x = true;
                rep(i, 0, n){
                    x ? test += pos[a] : test += pos[b];
                    x = !x;
                }
                cout << test << '\n';
                return 0;
                
            }
        }
    }
    rep(i, 0, 6){
        test = "";
        rep(j, 0, n)
            test += pos[i][0];
        rep(j, 0, n)
            test += pos[i][1];
        rep(j, 0, n)
            test += pos[i][2];
        bool can =true;
        rep(j, 0, 3*n - 1){
            if (test.substr(j, 2) == s || test.substr(j, 2) == t){
                    can = false;
                    break;
                }
        }
        if (can){
            cout<< "YES\n" << test << '\n';
            return 0;
        }                
    }
    cout << "NO\n";
    return 0;
}
