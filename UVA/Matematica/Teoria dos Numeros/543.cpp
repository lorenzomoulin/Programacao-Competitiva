#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
    _sieve_size = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
    }
}



bool isPrime(ll N){
    if (N <= _sieve_size)   return bs[N];
    for (int i = 0; i < (int)primes.size(); i++)
        if (N % primes[i] == 0) return false;
    return true;
}

int index(int primo){
    for (int i = 0; i < _sieve_size; i++){
        if (primo == primes[i]) return i;
    }
}

int main(){
    
    sieve(1000000);
    
    while (true){
        int n;
        cin >> n;
        if (!n) break;
        
        int soma[2] = {0,0};
        int primo;
        for (int i = n-1; i >=2; i--){
            if  (isPrime(i)){
                primo = i;
                break;
            }
        }
        //cout << index(primo);
        for (int i = index(primo); i >= 0; i--){
            soma[1] = primes[i];
            for (int j = 0; j <=i; j++){
                if  (soma[1] + primes[j]  == n){
                    soma[0] = primes[j];
                    goto PAR;
                }
            }
            soma[1] = 0;
        }
        PAR:
        if (!soma[0])  cout << "Goldbach's conjecture is wrong." << endl;
        else    cout << n << " = " << soma[0] << " + " << soma[1] << endl;
    }
    return 0;
}
