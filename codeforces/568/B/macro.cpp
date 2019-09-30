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
    int n;
    cin >> n;
    string s1, s2;
    while(n--){
        cin >> s1 >> s2;
        if (sz(s2) < sz(s1)){
            cout << "NO\n";
            continue;
        }
        int i = 0, j = 0;
        if (s2[0] != s1[0]){
            cout << "NO\n";
            continue;
        }
        i++, j++;
        char ant = s2[0];
        bool pode = true;
        while(i < sz(s1)){
            if (s1[i] != s2[j] && ant == s2[j])
                j++;
            else if (s1[i] == s2[j])
                i++, j++;
            else if (s1[i] != s2[j] && ant != s2[j]){
                pode = false;
                break;
            }
            ant = s2[j - 1];
        }
        if (pode){
            while(j < sz(s2)){
                if (s2[j] != ant){
                    pode = false;
                    break;
                }
                j++;
            }
            if (pode)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
            cout << "NO\n";
    }
    return 0;
}
