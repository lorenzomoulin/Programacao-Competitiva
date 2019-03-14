#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
typedef vector<int> vi;

int sievesize;
bitset<1009> bs;
vi primes;

void sieve(int n){
    sievesize = n + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i <= sievesize; i++){
        if (bs[i]){
            for (int j = i * i; j <= sievesize; j += i) bs[j] = 0;
            primes.push_back(i);
        }
    }
}
