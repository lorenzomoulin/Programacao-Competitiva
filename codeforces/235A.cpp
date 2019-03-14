#include <iostream>
using namespace std;

long long gcd(long long a, long long b){return b == 0? a: gcd(b, a % b);}

int main(){
    long long n;
    cin >> n;
    if (n <= 2) cout << n << endl;
    
    else if (n % 2)  cout << n*(n-1)*(n-2) << endl;
    else if (n % 2 == 0 && n >=4 && n % 3)  cout << n*(n -1)*(n-3) << endl;
    else cout << (n-1)*(n-2)*(n-3) << endl;
    return 0;
}
