#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool isPrime(ll N) {
	if (N < 0) return isPrime(-N);
	for(ll i=2; i*i <= N; i++) {
		if (N % i == 0) return false;
	}
	return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    cout << ((isPrime(n) || n == 1LL) ? "N" : "S") << '\n';
   return 0;
}
