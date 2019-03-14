#include <iostream>
#include <cmath>

using namespace std;
typedef unsigned long long ull;


ull sum (ull n){
    ull s = 0;
    while (n){
        s += n%10;
        n/=10;
    }
    return s;
}

int main(){
    ull n;
    cin >> n;
    ull a = 0;
    while (a <= n)  a = a*10 + 9;
    a/=10;    
    cout << sum(a) + sum(n-a) << endl;
    return 0;
}
