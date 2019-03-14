#include <iostream>
#include <set>
using namespace std;

typedef long long ll;
set<ll> factors;

void p_fac(ll n){
    ll i = 2;
    while(i*i <= n){
        if (n % i == 0){
            factors.insert(i);
            while (n % i == 0)    n /= i;            
        }
        i++;
    }
    if (n != 1) factors.insert(n);
}

ll count(){ return (1 << factors.size()) - (factors.size() + 1);}

int main(){
    ll n;
    cin >> n;
    p_fac(n);
    cout << count() << endl;
    return 0;
}
