#include <iostream>
#include <vector>
#include <cstring>
#include <bitset>
using namespace std;
#define MAXN 10000009

typedef long long ll;

bool prime(ll n){
    if (n < 0)  return prime(-n);
    for (ll i = 2; i * i <= n; i++){
        if (n % i == 0) return false;
    }
    return true;
}

ll phi(ll n){
    ll result = n;
    
    if (prime(n))   return (n-(ll)1);
    
    for (ll p = 2; p * p <= n; p++){
        if (n % p == 0){
            while(n % p == 0){
                n /= p;
            }
            result -= result/p; 
        }
    }
    
    if (n > 1)
        result -= result/n;
    return (ll)result;
}

int main(){
    ll n;
    
    while(cin >> n){
        cout << phi(n)/(ll)2 << endl;
    }
    return 0;
}
