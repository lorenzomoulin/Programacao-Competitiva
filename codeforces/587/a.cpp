/*
    Author: hidrogenio3
    
*/
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
    int n, res = 0;
    
    cin >> n >> s;
    for(int i = 1; i < n; i += 2){
        if (s[i] == s[i-1]){
            res++;
            if(s[i] == 'a')
                s[i-1] = 'b';
            else 
                s[i-1] = 'a';
        }
    }
    cout << res << '\n' << s << '\n'; 
    return 0;
}
