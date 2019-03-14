#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    while (scanf("%lld", &n)!=EOF){
        long long x = 1;
        int i = 1;
        while (x % n != 0){
            x = (10*x + 1) % n;
            i++;
        }
        cout << i << endl;
    }

    return 0;
}
