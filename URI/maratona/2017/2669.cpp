#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> base;
 
 
const int maxs = 26e5 + 9;
void fft(vector<base> &a, bool invert) {
	int n = (int)a.size();
	for(int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		for(; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for(int len = 2; len <= n; len <<= 1) {
		double ang = 2*acos(-1.0)/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for(int i = 0; i < n; i += len) {
			base w(1);
			for(int j = 0; j < len/2; j++) {
				base u = a[i+j], v = a[i+j+len/2] * w;
				a[i + j] = u + v;
				a[i + j + len/2] = u - v;
				w *= wlen;
			}
		}
	}
	for (int i = 0; invert && i < n; i++) a[i] /= n;
}

void convolution(vector<base> a, vector<base> b, vector<base> &res) {
	int n = 1;
	while(n < max(a.size(), b.size())) n <<= 1;
	n <<= 1;
	a.resize(n), b.resize(n);
	fft(a, false); fft(b, false);
	res.resize(n);
	for(int i=0; i<n; ++i) res[i] = a[i]*b[i];
	fft(res, true);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    string s;
    
    cin >> s;
    int n = sz(s), pn = 0;
    rep(i, 0, n) pn += s[i] - 'a' + 1;
    //cout << "n = " << n << '\n';
    vector<base> a(pn), b(pn), res;
    int sum = 0;
    rep(i, 0, n - 1){
        sum += s[i] - 'a' + 1;
        a[sum] = 1;
        b[pn - sum] = 1;
    }
    convolution(a, b, res);
    int ans = 0;
    rep(i, 0, 2*pn){
        if (i > pn && (int)(res[i].real() + 0.5) > 0){
            res[i - pn] = base(1);
        }
        
    }
    rep(i, 0, pn) {
        if ((int)(res[i].real() + 0.5) > 0)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}
