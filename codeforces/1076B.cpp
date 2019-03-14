#include <iostream>
#include <vector>
#include <bitset>
#include <cstring>
using  namespace std;
typedef long long ll;

bool isPrime(ll n){
    if (n < 0)  return isPrime(-n);
    for (ll i = 2; i*i <=n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

ll first_prime_divide_n(ll n){
    ll i = 2;
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0)  {if (isPrime(i))   return i;}
        
    }
}  

int main(){
    ll n;
    cin >> n;
    ll sum = 0;
    if (n % (ll)2 == 0){    cout << n/(ll)2 << endl; return 0;}
    while (n > (ll)0) {
        if (n % (ll)2 == 0){
            cout << sum + n/(ll)2 << endl; return 0;
        }
        ll d = first_prime_divide_n(n);
        //cout << d << endl;
        n -= d;
        sum++;
    }
    
    cout << sum << endl;
    
    return 0;
} 
