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
    string a[3] = {"Sunny", "Cloudy", "Rainy"};
    string s;
    cin >> s;
    if (!s.compare("Sunny"))
        cout << a[1] << '\n';
    else if (!s.compare("Cloudy"))
        cout << a[2] << '\n';
    else
        cout << a[0] << '\n';
    return 0;
}
