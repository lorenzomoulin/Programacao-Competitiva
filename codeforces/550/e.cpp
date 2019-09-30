#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define MOD 26
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    string s1,s2,s3,res;
    int n;
    char c = 0;  
    cin >> n >> s1 >> s2;
    s3.resize(n + 1);
    for(int i = n - 1; i >= 0; i--){
        s3[i + 1] = (s2[i]-2*'a'+s1[i]+c)%MOD+'a';
        c = (s2[i]+s1[i]+c-2*'a')/MOD;
    }
    int i = 1;
    if (c){
        s3[0] = c+'a';
        i = 0;
    }
    
    int r = 0;
    for (;i <= n; i++){
        int d = s3[i]+MOD*r-'a';
        char c = d/2+'a';           
        res.push_back(c);
        r = (s3[i]-'a')%2;
    }
    if (sz(res) > n){
        cout << res.substr(1, n);
    }
    else cout << res;
    cout << '\n';
    return 0;
}
