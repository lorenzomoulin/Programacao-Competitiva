#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n){
    if (n < 0) return isPrime(-n);
    for(int i = 2; i*i <= n; ++i)
        if( n % i == 0)
            return false;
    return true;
}

bool palindrome(int n){
    int res = 0, copy = n;
    while (n  >0){
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res == copy;
}

int main(){
    int i = 999999999;
    cout << palindrome(123321) << endl;
    cout << isPrime(11) << endl;
    for (i; i >= 2; i--){
        if (isPrime(i)){
            if (palindrome(i)){
                cout << i << endl;
                break;
            }
                
        }
    }
    return 0;
}
