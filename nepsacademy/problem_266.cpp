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
    int sum = 0;
    trav(a, s)
        sum += a - '0';
    cout << ((s[s.size() - 1]  - '0' )% 2 == 0 ? 'S' : 'N') << '\n';
    cout << (sum % 3 == 0 ? 'S' : 'N') << '\n';
    cout << ((s[s.size() - 1] - '0') % 5 == 0 ? 'S' : 'N') << '\n';
    return 0;
}
