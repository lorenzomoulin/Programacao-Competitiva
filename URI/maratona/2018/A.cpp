#include <cstdio>
#include <iostream>

using namespace std;

int gcd(int a, int b){  return b == 0? a: gcd(b, a%b);}

int main(){
    int i,d;
    scanf("%d.%d", &i, &d);
    cout << 36000/gcd(36000, 100*i + d) << endl;
    return 0;
}
