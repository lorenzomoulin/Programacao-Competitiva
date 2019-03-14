#include <iostream>

using namespace std;
typedef unsigned long long ll;

int n;

ll gcd(ll a, ll b){
    return b? gcd(b, a % b): a;
}

bool prime_factor(ll n){
    //cout << "n: " << n << endl;
    for (ll i = 2; i * i <= n; i++){
        
        
        
        while (n % i == 0 && (i == 2 || i == 3)){
            n /= i;
            //cout << "divisor: " << i << " ";
        }
        //cout << endl; //<< endl;
        if (i > 3 && n % i == 0){
            return false;
        }
    }
    if (n > 3)  return false;   
    return true;
}

bool lcm(ll a[]){
    ll ans = a[0];
    
    for (int i = 1; i < n; i++){
        ans = a[i]*(ans/gcd(ans, a[i]));
    }
    //cout << ans << endl;
    for (int i = 0; i < n; i++){
        //cout << ans/a[i] << " ";
        if (!prime_factor(ans/a[i]))    return false;
    }
    return true;
}



int main(){
    cin >> n;
    ll a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    bool res = lcm(a);
    res?cout << "Yes\n":cout << "No\n";
    return 0;       
}
