#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

ull gcd(ull a, ull b){  return (b == 0) ? a : gcd(b, a % b);}

int main(){
    int t;
    cin >> t;
    int cases = 1;
    while(t--){
        string s;
        cin >> s;
        bitset<32> bs(s);
        unsigned long long a = bs.to_ullong(); 
        cin >> s;
        bs = bitset<32>(s);
        unsigned long long b = bs.to_ullong();
        if(gcd(a, b) != 1ULL)
            cout << "Pair #" << cases << ": All you need is love!\n";
        else 
            cout << "Pair #" << cases << ": Love is not all you need!\n"; 
        cases++;
    }

    return 0;
}
