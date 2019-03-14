#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    if (n >= 0) {cout << n << endl; return 0;}
    ((-n) % 10 > (((-n) / 10) % 10)) ? cout << n / 10 << endl : cout << ((n / 100)*10 - (-n)% 10) << endl; 
    return 0;
}
