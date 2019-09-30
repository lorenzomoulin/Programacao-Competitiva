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
    
    string s1, s2;
    while (cin >> s1 >> s2){
        int i = 0, j =0;
        for (i = 0, j = 0; i < sz(s2) && j < sz(s1); i++)
            if (s2[i] == s1[j])
                j++;
        cout << (j == sz(s1) ? "Yes\n" : "No\n");
    }
    return 0;
}
