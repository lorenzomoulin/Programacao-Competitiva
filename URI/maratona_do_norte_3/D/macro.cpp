#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename T>
T modMul(T a, T b, T m) {
	T x = 0, y = a % m;
	while (b > 0) {
		if (b % 2 == 1) x = (x + y) % m;
		y = (y * 2) % m; b /= 2;
	}
	return x % m;
}

template<typename T>
T modExp(T a, T b, T m) {
    if (b == 0) return (T)1;
    T c = modExp(a, b / 2, m);
    c = (c * c) % m;
    if (b % 2 != 0) c = (c*a) % m;
    return c;
}


#define MAXN 1000009
ll fat[MAXN];
void preprocessfat(ll m) {
    fat[0] = 1;
    for(ll i=1; i<MAXN; i++)
        fat[i] = (i*fat[i-1])%m;
}

ll fib[MAXN];
void fibo(){
    fib[0] = fib[1] = 1;
    for (ll i = 2; i < MAXN; i++)
        fib[i] = (fib[i - 1] + fib[i-2]) % MOD;   
}

int readInt() {
	bool minus = false;
	int ans = 0;
	char c;
	while (c = getchar()) {
		if (c == '-') break;
		if (c >= '0' && c <= '9') break;
	}
	if (c == '-') minus = true;
	else ans = c-'0';
	while (c = getchar()) {
		if (c < '0' || c > '9') break;
		ans = ans*10 + (c - '0');
	}
	return minus ? -ans : ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    ll n = readInt(); //cin >> n;
    preprocessfat(MOD);
    fibo();
    ll pot = modExp((ll)2, (ll)n, (ll)MOD);
    ll res = (fib[n] * fat[n] ) % MOD;
    res *= pot;
    printf("%lld\n", res % MOD);
    //cout << res % MOD << '\n';
    
    return 0;
}
