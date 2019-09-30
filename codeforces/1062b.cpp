#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define ispow(S) (!(S & (S - 1)))
#define LSONE(x) (x & (-x))
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define MAXN 10000009
ll sievesize, numDiffPF[MAXN];
bitset<MAXN> bs;
vector<ll> primes;
int maior = 0;
bool tem = false;
void sieve(ll n) {
	sievesize = n + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= sievesize; i++) {
		if (bs[i]) {
			for (ll j = i * i; j <= (ll)sievesize; j += i) bs[j] = 0;
			primes.push_back(i);
		}
	}
}

ll primeFactors(ll N) {
	set<int> factors;
	ll PF_idx = 0, PF = primes[PF_idx];
	while (PF * PF <= N) { 
	    int cont = 0;
		while (N % PF == 0) {
		    
			N /= PF;
			factors.insert(PF);
			cont++;
		}
		if (maior && cont != maior)
		    tem = true;
		maior = max(maior, cont);
		PF = primes[++PF_idx];
	}
	if (N != 1) {factors.insert(N); if (maior != 1) tem = true;}
	ll res = 1;
	trav(a, factors)
	    res *= a;
	return res;
}

int maiorpot(int n){
    if (ispow(n))
        return n;
    while(!ispow(n)){
        n -= LSONE(n);
    }
    return (n << 1);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    sieve(1000009);
    ll n, res = 0, ant;
    cin >> n;
     ant = n;
    n = primeFactors(n);
    if (n == ant){
        cout << n << " 0\n";
        return 0;
    }
    if (tem){
        res = log2(maiorpot(maior)) + 1;
        //cout << "oi";
    }
    else{
        if (maiorpot(maior) == maior)
            res = log2(maior);
        else
            res = log2(maiorpot(maior)) + 1;
    }
    cout << n << " " << res << '\n';
    return 0;
}
