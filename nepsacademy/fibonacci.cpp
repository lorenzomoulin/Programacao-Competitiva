#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fib(ll n){
    if (n == 0 || n == 1)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main(){
    ll n;
    cin >> n;
    cout << fib(n) << "\n";
    return 0;
}
