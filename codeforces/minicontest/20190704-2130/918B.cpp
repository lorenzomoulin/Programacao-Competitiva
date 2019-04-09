#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    map<string ,string> lookup;
    rep(i, 0, n){
        string name, ip;
        cin >> name >> ip;
        lookup[ip] = name;
    }
    rep(i, 0, m){
        string c, ip;
        cin >> c >> ip;
        cout << c << " " << ip << " #" << lookup[ip.substr(0, ip.size() - 1)]<< endl;     
    }
    return 0;
}
