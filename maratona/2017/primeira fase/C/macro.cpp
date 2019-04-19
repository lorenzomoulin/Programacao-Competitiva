#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
#define trav(a, x) for(auto &a: x)
using namespace std; 
  
typedef long long int ll; 
  
// Utility function to find 
// GCD of 'a' and 'b' 
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b); 
} 

ll lcm(ll a, ll b){
    return a*(b/gcd(a, b));
}

// Returns LCM of array elements 
ll findlcm(ll arr[], ll n) 
{ 
    // Initialize result 
    ll ans = arr[0]; 
  
    // ans contains LCM of arr[0], ..arr[i] 
    // after i'th iteration, 
    for (ll i = 1; i < n; i++) 
        ans = (((arr[i] * ans)) / 
                (gcd(arr[i], ans))); 
  
    return ans; 
} 

vector<ll> divisores;

void divisors(ll n) 
{ 
    // Note that this loop runs till square root 
    for (ll i=1; i * i <= n; i++) 
    { 
        if (n%i == 0) 
        { 
            // If divisors are equal, print only one 
            if (n/i == i) 
                divisores.pb(i);
  
            else // Otherwise print both 
                 divisores.pb(i), divisores.pb(n / i);
        } 
    } 
} 



int main ()
{
	ll N, L, i, m, r = 0;
	scanf ("%lld %lld", &N, &L);
	ll n[N];
	for (i = 0; i < N; i++) scanf ("%lld", &(n[i]));
	ll mmc = findlcm(n, N);
    ll menor = L / mmc;
    ll maior = menor*mmc;
    divisors(maior);
    ll res = 0;
    sort(all(divisores));
    trav(a, divisores){
        if (lcm(a, mmc) == maior){
            cout << a << "\n";
            return 0;
        }
    }
    cout << maior << endl;
    
	return 0;
}
