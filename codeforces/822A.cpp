#include <iostream>
#include <cmath>
using namespace std;

long long fat(int n){
    long long f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;    
}

int main(){
    int a, b; cin >> a >> b;
    a < b? cout << fat(a) << endl: cout << fat(b) << endl;
    return 0;
}
