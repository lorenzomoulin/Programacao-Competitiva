#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll fib[5001];
void calc(){
    fib[0] = 0;
    fib[1] = 1;
    rep(i, 2, 5002)
        fib[i] = fib[i - 1] + fib[i - 2];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    calc();
    int n;
    while(cin >> n){
        cout << "The Fibonacci number for " << n << " is" << fib[n] << '\n';
    }
    return 0;
}
